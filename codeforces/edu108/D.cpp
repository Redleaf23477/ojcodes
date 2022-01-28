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

int n;
vector<LL> a, b;

void init() {
    cin >> n;
    a.assign(n+1, 0), b.assign(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
}

void process() {
    vector<LL> dot(n+1, 0), pre(n+1, 0); {
        for (int i = 1; i <= n; i++) dot[i] = a[i] * b[i];
        for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + dot[i];
    }
    LL ans = pre[n];
    // odd
    for (int mid = 1; mid <= n; mid++) {
        LL tmp = a[mid] * b[mid];
        for (int ext = 1; mid-ext > 0 && mid+ext <= n; ext++) {
            int l = mid-ext, r = mid+ext;
            tmp += a[r] * b[l] + a[l] * b[r];
            debug("odd", ext, l, r, tmp, (pre[r]-pre[l-1]), ans - (pre[r]-pre[l-1] + tmp));
            ans = max(ans, pre[n] - (pre[r]-pre[l-1]) + tmp);
        }
    }
    // even
    for (int mid = 1; mid <= n; mid++) {
        LL tmp = 0;
        for (int ext = 1; mid-ext+1 > 0 && mid+ext <= n; ext++) {
            int l = mid-ext+1, r = mid+ext;
            tmp += a[r] * b[l] + a[l] * b[r];
            debug("even", ext, l, r, tmp, (pre[r]-pre[l-1]), ans - (pre[r]-pre[l-1] + tmp));
            ans = max(ans, pre[n] - (pre[r]-pre[l-1]) + tmp);
        }
    }
    cout << ans << endl;
}

