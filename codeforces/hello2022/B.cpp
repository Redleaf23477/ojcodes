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
void solve();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    cout.flush();
    return 0;
}

void init() {
}

void solve() {
    int n; cin >> n;
    using T = tuple<LL,LL,LL>;
    vector<T> arr(n); {
        for (auto &[a, b, c] : arr) cin >> a >> b >> c;
    }
    const LL INF = (LL)1e15;
    LL L = -1, R = -1;
    map<LL, set<LL>> mp;
    LL ans = -1;
    bool ans_same = false;
    for (int i = 0; i < n; i++) {
        auto [l, r, c] = arr[i];
        mp[l].insert(c);
        mp[r].insert(c);
        if (L == -1) {
            L = l, R = r;
            ans = c, ans_same = true;
        } else {
            if (l < L && R < r) {
                L = l, R = r;
                ans = c, ans_same = true;
            } else if (l == L && R < r) {
                L = l, R = r;
                ans = c, ans_same = true;
            } else if (l < L && R == r) {
                L = l, R = r;
                ans = c, ans_same = true;
            } else if (l < L) {
                ans = c + *mp[R].begin();
                ans_same = false;
                L = l;
            } else if (R < r) {
                ans = c + *mp[L].begin();
                ans_same = false;
                R = r;
            } else if (l == L && r == R) {
                if (c < ans) {
                    ans = c;
                    ans_same = true;
                }
            } else if (l == L) {
                LL tmp = c + *mp[R].begin();
                if (tmp < ans) {
                    ans = tmp;
                    ans_same = false;
                }
            } else if (r == R) {
                LL tmp = c + *mp[L].begin();
                if (tmp < ans) {
                    ans = tmp;
                    ans_same = false;
                }
            }
        }
        cout << ans << endl;
    }
}
