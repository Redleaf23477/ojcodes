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
    string str; cin >> str;
    int single = 0, pair = 0, mid = 0;
    if (n % 2 == 1 && str[n/2] == '0') mid++;
    for (int i = 0; i < n/2; i++) {
        if (str[i] == '0' && str[i+n/2+(n%2==1)] == '0') pair++;
        else if (str[i] == '0') single++;
    }
    for (int i = n/2 + (n%2==1); i < n; i++) {
        if (str[i] == '0' && str[i-n/2-(n%2==1)] != '0') single++;
    }
    debug(single, pair, mid);
    if (mid == 1) {
        if (single == 0 && pair == 0) {
            cout << "BOB" << endl;
        } else if (single == 0) {
            cout << "ALICE" << endl;
        } else if (single == 1) {
            cout << "DRAW" << endl;
        } else {
            cout << "ALICE" << endl;
        }
    } else {
        cout << "BOB" << endl;
    }
}

