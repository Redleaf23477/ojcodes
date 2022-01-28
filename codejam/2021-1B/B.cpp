// by redleaf23477
// test 2
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
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, A, B;
vector<LL> arr;

void init() {
    cin >> n >> A >> B;
    arr.assign(n+1, 0); for (int i = 1; i <= n; i++) cin >> arr[i];
}

bool good(int big) {
    vector<LL> has(big+1, 0); has[big] = 1;
    vector<LL> need = arr;
    for (int i = big, j = n; j > 0; j--) {
        while (i > j) {
            if (i-A > 0) has[i-A] = min(10000ll, has[i-A] + has[i]);
            if (i-B > 0) has[i-B] = min(10000ll, has[i-B] + has[i]);
            has[i] = 0;
            i--;
        }
        /*
        cerr << "has: ";
        for (int i = 1; i <= big; i++) cerr << has[i] << " ";
        cerr << endl;
        */
        has[i] -= need[j];
        if (has[i] < 0) return false;
    }
    return true;
}

void process() {
    int ans = -1;
    for (int mid = 420; mid >= n; mid--) {
        if (good(mid)) ans = mid;
    }
    if (ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}

