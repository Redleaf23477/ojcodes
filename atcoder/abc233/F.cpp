// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// variadic print template, requires c++17
template<typename Sep, typename Head, typename... Tail>
void fold_print(Sep sep, Head&& h, Tail&&... args) {
    ((std::cerr << h) << ... << (std::cerr << sep, args));
}
#ifdef REDLEAF_LOCAL
#define debug(...) do {                                     \
    std::cerr << "[DEBUG:" << __LINE__ << "] ";             \
    std::cerr << "(" << #__VA_ARGS__ ") = (";               \
    fold_print(", ", __VA_ARGS__);                          \
    std::cerr << ")\n";                                     \
    std::cerr.flush();                                      \
} while (0)
#define info(...) do {                                      \
    std::cerr << "[INFO:" << __LINE__ << "] ";              \
    fold_print(" ", __VA_ARGS__);                           \
    std::cerr << "\n";                                      \
    std::cerr.flush();                                      \
} while (0)
#else
#define debug(...) do { } while (0)
#define info(...) do { } while (0)
#endif
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

using Edge = tuple<int,int>;  // to, op_idx

int n;
vector<int> arr;
vector<int> pos;
vector<tuple<int,int>> ops;
vector<vector<Edge>> graph;

void init() {
    cin >> n;
    arr.assign(n, -1); 
    pos.assign(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; arr[i]--;
        pos[arr[i]] = i;
    }

    int m; cin >> m;
    graph.assign(n, vector<Edge>());
    ops.emplace_back(-1, -1);   // insert trash for 1-index
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
        ops.emplace_back(u, v);
    }
}

vector<Edge> pa;
stack<int> order;
vector<int> ans;

void dfs_tree(int u) {
    order.emplace(u);
    for (auto [v, op_idx] : graph[u]) {
        if (get<0>(pa[v]) != -1) continue;
        pa[v] = make_tuple(u, op_idx);
        dfs_tree(v);
    }
}

bool swap_to_sort(int u) {
    // u is the vertex idx, number u should be swap to here
    int v = pos[u];
    if (get<0>(pa[v]) == -1) return false;  // different component

    // find lca
    vector<bool> v_to_root_path(n, false); {
        int tmp = v;
        v_to_root_path[v] = true;
        while (get<0>(pa[tmp]) != tmp) {
            int p = get<0>(pa[tmp]);
            v_to_root_path[p] = true;
            tmp = p;
        }
    }
    int lca = -1; {
        int tmp = u;
        while (!v_to_root_path[tmp]) {
            tmp = get<0>(pa[tmp]);
        }
        lca = tmp;
    }
    if (lca == -1) return false;
    // v -> lca
    {
        int tmp = v;
        while (tmp != lca) {
            auto [p, op_idx] = pa[tmp];
            auto [x, y] = ops[op_idx];
            swap(arr[x], arr[y]);
            pos[arr[x]] = x, pos[arr[y]] = y;
            ans.emplace_back(op_idx);
            tmp = p;
        }
    }
    // lca -> u
    {
        vector<int> buff;
        int tmp = u;
        while (tmp != lca) {
            auto [p, op_idx] = pa[tmp];
            buff.emplace_back(op_idx);
            tmp = p;
        }
        for (int i = buff.size() - 1; i >= 0; i--) {
            int op_idx = buff[i];
            auto [x, y] = ops[op_idx];
            swap(arr[x], arr[y]);
            pos[arr[x]] = x, pos[arr[y]] = y;
            ans.emplace_back(op_idx);
        }
    }
    return true;
}

bool solve(int u) {
    while (!order.empty()) order.pop();
    pa[u] = make_tuple(u, -1);
    dfs_tree(u);
    while (!order.empty()) {
        int u = order.top(); order.pop();
        if (!swap_to_sort(u)) return false;
    }
    return true;
}

void process() {
    ans.clear();
    pa.assign(n, make_tuple(-1, -1));
    bool good = true;
    for (int i = 0; i < n && good; i++) {
        auto [p, op_idx] = pa[i];
        if (p == -1) {
            good = solve(i);
        }
    }
    if (good) {
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

