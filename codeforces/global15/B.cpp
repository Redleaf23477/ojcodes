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
    int n; cin >> n;
    vector<pair<vector<int>, int>> arr(n, make_pair(vector<int>(5), -1));
    for (int i = 0; i < n; i++) {
        arr[i].second = i;
        for (int j = 0; j < 5; j++) {
            cin >> arr[i].first[j];
        }
    }
    auto lt = [](const pair<vector<int>, int> &lhs, const pair<vector<int>,int> &rhs) {
        int l = 0;
        const auto la = lhs.first, ra = rhs.first;
        for (int i = 0; i < 5; i++) l += la[i] < ra[i];
        return l < 3;
    };
    sort(range(arr), lt);
    /*
    for (int i = 0; i < n; i++) {
        debug(i, arr[i].second);
    }
    */
    for (int i = 0; i+1 < n; i++) {
        if (!lt(arr[i], arr[n-1])) {
            cout << -1 << endl; return;
        }
    }
    cout << arr.back().second+1 << endl;
}

