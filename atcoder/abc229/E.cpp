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

void init() {
}

struct DisjointSet {
    int n;
    int sz;  // number of components
    vector<int> pa;
    DisjointSet(int _n) : n(_n), sz(_n), pa(_n) {
        iota(range(pa), 0); 
    }
    int findpa(int u) {
        if (pa[u] == u) return u;
        else return pa[u] = findpa(pa[u]);
    }
    bool same(int u, int v) {
        return findpa(u) == findpa(v); 
    }
    void uni(int u, int v) {
        if (same(u, v)) return;
        sz -= 1;
        pa[findpa(u)] = findpa(v);
    }
    int size() { return sz; }
};

void process() {
    int vn, en; cin >> vn >> en;
    vector<vector<int>> graph(vn); {
        for (int i = 0; i < en; i++) {
            int u, v; cin >> u >> v; u--, v--;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
    }
    DisjointSet ds(vn);
    vector<int> ans(vn);
    for (int i = vn-1; i >= 0; i--) {
        ans[i] = ds.size() - i - 1;
        for (auto v : graph[i]) {
            if (v > i) ds.uni(v, i);
        }
    }
    for (auto x : ans) cout << x << endl;
}
