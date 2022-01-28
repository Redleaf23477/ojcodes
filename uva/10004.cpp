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

bool dfs(int u, vector<vector<int>> &graph, vector<int> &color) {
    int c1 = color[u], c2 = 1 - c1;
    for (auto v : graph[u]) {
        if (color[v] == -1) {
            color[v] = c2;
            if (dfs(v, graph, color) == false) return false;
        } else if (color[v] == c1) {
            return false;
        } else {
            continue;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int vn, en;
    while (cin >> vn && vn) {
        cin >> en;
        vector<vector<int>> graph(vn);
        vector<int> color(vn, -1);  // -1: not visited, 0: black, 1: white
        for (int i = 0; i < en; i++) {
            int u, v; cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        bool bi = true;
        for (int i = 0; i < vn; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                bi = bi && dfs(i, graph, color);
            }
        }
        if (bi) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    cout.flush();
    return 0;
}

void init() {
}

void process() {
}

