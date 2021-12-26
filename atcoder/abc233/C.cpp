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
    int n; cin >> n;
    LL X; cin >> X;
    vector<vector<LL>> arr(n);
    for (auto &x : arr) {
        int m; cin >> m;
        x.assign(m, 0);
        for (auto &y : x) cin >> y;
    }

    map<LL,LL> mp[2];
    for (auto x : arr[0]) {
        if (mp[0].count(x) == 0) mp[0][x] = 0;
        mp[0][x] += 1;
    }
    for (int k = 1; k < n; k++) {
        int i = k & 1, j = 1 - i;
        mp[i].clear();
        for (auto [u, cnt] : mp[j]) {
            for (auto y : arr[k]) {
                __int128 tmp = u; tmp *= y;
                if (tmp > X) continue;
                if (mp[i].count(u * y) == 0) mp[i][u * y] = 0;
                mp[i][u * y] += cnt;
            }
        }
    }
    auto &mp_ans = mp[(n - 1) & 1];
    if (mp_ans.count(X) == 0) cout << 0 << endl;
    else cout << mp_ans[X] << endl;
}

