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

void process() {
    int n, m; cin >> n >> m;
    vector<int> deg(n, 0);
    vector<vector<int>> graph(n); {
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; u--, v--;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
            deg[u] += 1, deg[v] += 1;
        }
    }
    int rest = n;
    vector<bool> vis(n, false);
    function<bool(int,int)> dfs = [&](int u, int p) {
        vis[u] = true;
        rest -= 1;
        if (deg[u] > 2) return false;
        for (auto v : graph[u]) {
            if (v == p) continue;
            if (vis[v]) return false;
            if (!dfs(v, u)) return false;
        }
        return true;
    };
    bool good = true;
    for (int i = 0; i < n && good; i++) {
        if (deg[i] == 0) rest -= 1;
        else if (deg[i] == 1 && !vis[i]) {
            good = dfs(i, i);
        }
    }
    cout << (good && rest == 0? "Yes" : "No") << endl;
}

