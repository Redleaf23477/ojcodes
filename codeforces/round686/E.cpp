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

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

LL n;
vector<vector<int>> graph;

void init() {
    cin >> n;
    graph.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

void process() {
    LL ans = 0;
    tuple<int,int> edge;
    vector<LL> sz(n, 0);
    vector<int> pa(n, 0);
    vector<bool> vis(n, false);
    function<LL(int, int)> dfs = [&](int u, int p) {
        vis[u] = true, sz[u] = 1;
        pa[u] = p;
        LL ans = 0;
        vector<int> child;
        for (auto v : graph[u]) {
            if (v == p) continue;
            if (vis[v]) { // is back edge
                edge = make_tuple(u, v);
                continue;
            } 
            child.emplace_back(v);
            ans += dfs(v, u);
            sz[u] += sz[v];
        }
        LL acc = 0;
        for (auto c : child) {
            ans += sz[c];
            ans += sz[c] * (sz[u]-1-acc-sz[c]);
            acc += sz[c];
        }
        return ans;
    };
    ans += dfs(0, 0);
    // cerr << var(ans) << endl;
    auto [u, v] = edge;
    if (sz[u] > sz[v]) swap(u, v);
    // cerr << var(u) << var(v) << endl;
    /*
    cerr << "sz = ";
    for (auto x : sz) cerr << x << " ";
    cerr << endl;
    */

    for (LL x = u, acc = 0; x != v; x = pa[x]) {
        ans += (sz[x]-acc) * (n - sz[x]);
        acc += (sz[x]-acc);
    }

    cout << ans << endl;
}

