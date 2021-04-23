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
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    while (true) {
        bool hasOdd = false;
        for (auto &x : arr) if (x % 2 == 1) hasOdd = true;
        if (hasOdd) break;
        for (auto &x : arr) x /= 2;
    }
    vector<vector<bool>> dp(2, vector<bool>(n*2000+10, false));
    dp[1][0] = true;
    for (int i = 0; i < n; i++) {
        int a = i%2, b = 1-a;
        for (int j = 0; j <= n*2000; j++) {
            dp[a][j] = dp[b][j];
            if (j-arr[i] >= 0 && dp[b][j-arr[i]]) dp[a][j] = true;
        }
    }
    int sum = accumulate(range(arr), 0);
    if (sum % 2 == 1) cout << 0 << endl;
    else if (dp[(n-1)%2][sum/2] == false) cout << 0 << endl;
    else {
        for (int i = 0; i < n; i++) if (arr[i] % 2 == 1) {
            cout << 1 << endl << i+1 << endl;
            break;
        }
    }
}

