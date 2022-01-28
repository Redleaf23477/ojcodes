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
        cout << "Case #" << t << ": ";
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
    LL K; cin >> K;
    set<LL> s; {
        for (int i = 0; i < n; i++) {
            LL x; cin >> x;
            s.insert(x);
        }
    }
    vector<LL> arr(range(s));
    n = arr.size();
    vector<LL> seg; {
        for (int i = 1; i < n; i++) {
            LL len = arr[i] - arr[i-1];
            seg.emplace_back(len/2);
            if (len-1-len/2 > 0) seg.emplace_back(len-1-len/2);
        }
        if (arr[0] != 1) seg.emplace_back(arr[0]-1);
        if (arr[n-1] != K) seg.emplace_back(K-arr[n-1]);
        sort(range(seg), greater<LL>());
    }
    LL ans = 0;
    for (int i = 0; i < 2 && i < (int)seg.size(); i++) {
        ans += seg[i];
    }
    cout << fixed << setprecision(10) << (double)ans / (double)K << endl;
}

