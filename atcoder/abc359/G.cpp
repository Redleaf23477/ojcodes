#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// small label -> less appearance
void relabel(vector<size_t> &A, vector<size_t> const &cnt, size_t N) {
    vector<size_t> index(N);
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&cnt](size_t lhs, size_t rhs) {
        return cnt[lhs] > cnt[rhs];
    });
    vector<size_t> mp(N);
    for (size_t i = 0; i < N; i++) {
        mp[index[i]] = i;
    }
    for (auto &x : A) {
        x = mp[x];
    }
}

struct LargeSolver {
    vector<size_t> const &A;
    vector<vector<size_t>> const &tree;
    size_t large_cnt;
    LargeSolver(vector<size_t> &a, vector<vector<size_t>> &t, size_t sc)
        : A(a), tree(t), large_cnt(sc) {}

    bool is_large(size_t x) { return A[x] < large_cnt; }

    vector<vector<size_t>> gsize;
    vector<vector<LL>> acc;
    void dfs1(size_t u, size_t pa) {
        if (is_large(u)) {
            gsize[u][A[u]] += 1;
        }
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs1(v, u);
            for (size_t g = 0; g < large_cnt; g++) {
                gsize[u][g] += gsize[v][g];
                acc[u][g] += acc[v][g] + gsize[v][g];
            }
        }
    }

    LL ans;
    void swap_root(size_t pa, size_t ch) {
        for (size_t g = 0; g < large_cnt; g++) {
            gsize[pa][g] -= gsize[ch][g];
            acc[pa][g] -= acc[ch][g] + gsize[ch][g];
        }
        for (size_t g = 0; g < large_cnt; g++) {
            gsize[ch][g] += gsize[pa][g];
            acc[ch][g] += acc[pa][g] + gsize[pa][g];
        }
    }
    void dfs2(size_t u, size_t pa) {
        // u to everyone
        if (is_large(u)) {
            ans += acc[u][A[u]];
        }
        // change root
        for (auto v : tree[u]) {
            if (v == pa) continue;
            swap_root(u, v);
            dfs2(v, u);
            swap_root(v, u);
        }
    }

    LL run() {
        gsize.assign(tree.size(), vector<size_t>(large_cnt, 0));
        acc.assign(tree.size(), vector<LL>(large_cnt, 0));
        ans = 0;
        dfs1(0, 0);
        dfs2(0, 0);
        return ans;
    }
};

struct SmallSolver {
    vector<size_t> const &A;
    vector<vector<size_t>> const &tree;
    size_t small_begin;
    SmallSolver(vector<size_t> &a, vector<vector<size_t>> &t, size_t sb)
        : A(a), tree(t), small_begin(sb) {}

    bool is_small(size_t x) { return A[x] >= small_begin; }

    vector<vector<size_t>> box;
    LL run() {
        box.assign(tree.size(), vector<size_t>());
        for (size_t i = 0; i < tree.size(); i++) {
            if (is_small(i)) {
                box[A[i]].emplace_back(i);
            }
        }

        /*
        for (size_t i = 0; i < box.size(); i++) {
            if (box[i].empty()) continue;
            cerr << "box[" << i << "]: ";
            for (auto x : box[i]) cerr << x << " ";
            cerr << endl;
        }
        */

        build_lca();

        LL ans = 0;
        for (size_t i = small_begin; i < tree.size(); i++) {
            ans += run_pairwise(i);
        }
        return ans;
    }

    vector<vector<size_t>> dp;
    vector<size_t> dep;
    void build_lca() {
        size_t N = tree.size();
        size_t lgN = log2(N) + 2;
        dp.assign(lgN, vector<size_t>(N, 0));
        dep.assign(N, 0);

        // init dp[0][u] = pa(u)
        dfs(0, 0);

        for (size_t k = 1; k < lgN; k++) {
            for (size_t i = 0; i < N; i++) {
                dp[k][i] = dp[k - 1][dp[k - 1][i]];
            }
        }
    }

    void dfs(size_t u, size_t pa) {
        dp[0][u] = pa;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }

    size_t jump(size_t u, size_t step) {
        size_t pw = 0;
        while (step > 0) {
            if (step & 1) u = dp[pw][u];
            step >>= 1;
            pw++;
        }
        return u;
    }

    LL tree_dist(size_t u, size_t v) {
        if (dep[u] > dep[v]) swap(u, v);

        LL ans = 0;
        ans += dep[v] - dep[u];
        v = jump(v, dep[v] - dep[u]);

        if (u == v) return ans;

        int lgN = dp.size();
        for (int pw = lgN - 1; pw >= 0; pw--) {
            if (dp[pw][u] == dp[pw][v]) continue;
            ans += (1ll << pw) * 2;
            u = dp[pw][u];
            v = dp[pw][v];
        }

        return ans + 2;
    }

    LL run_pairwise(size_t g) {
        auto &b = box[g];
        LL ans = 0;
        for (size_t i = 0; i < b.size(); i++) {
            for (size_t j = i + 1; j < b.size(); j++) {
                ans += tree_dist(b[i], b[j]);
            }
        }
        return ans;
    }
};


void solve() {
    size_t N; cin >> N;
    vector<vector<size_t>> tree(N);
    for (size_t i = 1; i < N; i++) {
        size_t u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<size_t> A(N), cnt(N, 0);
    for (auto &x : A) {
        cin >> x; x--;
        cnt[x] += 1;
    }
    relabel(A, cnt, N);
    /*
    cerr << "A = ";
    for (auto x : A) cerr << x << " ";
    cerr << endl;
    */

    size_t threshold = sqrt(N) + 1;
    size_t large_cnt = 0;
    for (auto x : cnt) large_cnt += (x > threshold);

    LL ans = 0;

    // big labels
    ans += LargeSolver(A, tree, large_cnt).run() / 2;

    // small labels
    ans += SmallSolver(A, tree, large_cnt).run();
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

