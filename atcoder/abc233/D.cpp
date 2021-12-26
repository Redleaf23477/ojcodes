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
LL K;
vector<LL> arr;

void init() {
    cin >> n >> K;
    arr.assign(n, 0);
    for (auto &x : arr) cin >> x;
}

LL f(int l, int r) {
    if (l == r) {
        return arr[l] == K;
    }
    int mid = (l + r)/2;
    LL ans = f(l, mid) + f(mid+1, r);
    vector<LL> left_suffix, right_prefix;
    left_suffix.emplace_back(arr[mid]);
    for (int i = mid-1; i >= l; i--) left_suffix.emplace_back(arr[i] + left_suffix.back());
    right_prefix.emplace_back(arr[mid+1]);
    for (int i = mid+2; i <= r; i++) right_prefix.emplace_back(arr[i] + right_prefix.back());
    // CHECK IF COMPLEXITY IS CORRECT
    sort(range(left_suffix));
    sort(range(right_prefix));
    for (auto x : left_suffix) ans += upper_bound(range(right_prefix), K-x) - lower_bound(range(right_prefix), K-x);
    return ans;
}

void process() {
    cout << f(0, n-1) << endl;
}

