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
vector<LL> arr;

void init() {
    cin >> n;
    arr.assign(n, 0);
    for (auto &x : arr) {
        LL u, v; cin >> u >> v;
        x = u + v;
    }
    sort(range(arr));
}

bool geq(LL guess, LL k, LL qi, vector<LL>::iterator it) {
    LL ql = qi - guess, qr = qi + guess;
    LL cnt = 0;
    cnt += it - lower_bound(arr.begin(), it, ql);
    cnt += upper_bound(it, arr.end(), qr) - it;
    return cnt >= k;
}

void process() {
    int q; cin >> q;
    while (q--) {
        LL u, v, k; cin >> u >> v >> k; u += v; 
        auto it = upper_bound(range(arr), u);
        LL l = 0, r = 2*100000, mid, ans = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (geq(mid, k, u, it)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << endl;
    }
}

