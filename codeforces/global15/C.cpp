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
    int T; cin >> T;
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
    LL n, k; cin >> n >> k;
    set<int> used;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        arr[i] = make_pair(u, v);
        used.insert(u);
        used.insert(v);
    }
    vector<int> unused;
    for (int i = 1; i <= 2*n; i++) {
        if (used.count(i) == 0) unused.emplace_back(i);
    }
    vector<pair<int,int>> con(unused.size()/2);
    LL ans = con.size() * (con.size()-1) / 2;
    for (size_t i = 0; i < con.size(); i++) {
        con[i] = make_pair(unused[i], unused[i+con.size()]);
    }
    /*
    for (auto p : con) {
        debug(p.first, p.second);
    }
    */
    auto inter = [](const pair<int,int> &lhs, const pair<int,int> &rhs) {
        bool a = lhs.first < rhs.first && rhs.first < lhs.second;
        bool b = lhs.first < rhs.second && rhs.second < lhs.second;
        return a != b;
    };
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            if (inter(arr[i], arr[j])) ans++;
        }
    }
    for (auto p1 : arr) {
        for (auto p2 : con) {
            if (inter(p1, p2)) ans++;
        }
    }
    cout << ans << endl;
}

