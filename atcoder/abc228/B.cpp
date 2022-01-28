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
    int T = 1;  // int T; cin >> T;
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
    int x; cin >> x; x--;
    vector<int> arr(n); {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }
    }
    int ans = 0; {
        vector<int> vis(n, false);
        while (!vis[x]) {
            ans += 1;
            vis[x] = true;
            x = arr[x];
        }
    }
    cout << ans << endl;
}

