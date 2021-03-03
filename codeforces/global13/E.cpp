// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int vn;
vector<vector<int>> tree;

void init() {
    cin >> vn;
    tree.assign(vn, vector<int>());
    for (int i = 1; i < vn; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
}

void process() {
    vector<int> fib(30, 1); {
        for (int i = 2; i < 30; i++) fib[i] = fib[i-1] + fib[i-2];
    }
    int fidx = -1; {
        for (int i = 0; i < 30; i++) if (fib[i] == vn) fidx = i;
    }
    if (fidx == -1) { cout << "NO" << endl; return; }

    vector<int> sz(vn, 0); // subtree size rooted at some rt

    function<tuple<int,int>(int,int,int)> cut = [&](int u, int pa, int fidx) {
        sz[u] = 1;
        for (auto v : tree[u]) {
            if (v == pa || v == -1) continue;
            auto res = cut(v, u, fidx);
            if (get<0>(res) != -1) { return res; }
            sz[u] += sz[v];
        }
        if (sz[u] == fib[fidx-1] || sz[u] == fib[fidx-2]) return make_tuple(pa, u);
        return make_tuple(-1, -1); // not found
    };

    function<bool(int,int)>check = [&](int rt, int fidx) {
        if (fidx == 0 || fidx == 1) return true;
        auto [u, v] = cut(rt, rt, fidx);  // rt -----> u -> v -> (trees)
        if (u == -1 || v == -1) return false;
        *find(range(tree[u]), v) = -1;
        *find(range(tree[v]), u) = -1;
        if (sz[v] == fib[fidx-1]) return check(u, fidx-2) && check(v, fidx-1);
        else return check(u, fidx-1) && check(v, fidx-2);
    };

    cout << (check(0, fidx)? "YES" : "NO") << endl;
}

