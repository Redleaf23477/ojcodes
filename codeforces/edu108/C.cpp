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

int n;
vector<LL> U, S;

void init() {
    cin >> n;
    U.assign(n, 0), S.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> U[i];
    for (int i = 0; i < n; i++) cin >> S[i];
}

void process() {
    map<int,vector<LL>> univ; {
        for (int i = 0; i < n; i++) {
            LL u = U[i], s = S[i];
            if (univ.count(u) == 0) univ[u] = vector<LL>();
            univ[u].emplace_back(s);
        }
        for (auto &[idx, u] : univ) {
            sort(range(u), greater<LL>());
        }
    }
    map<int,vector<LL>> bysize; {
        for (auto &[idx, u] : univ) {
            int sz = u.size();
            if (bysize.count(sz) == 0) {
                bysize[sz] = u;
            } else {
                auto &arr = bysize[sz];
                for (int i = 0; i < sz; i++) arr[i] += u[i];
            }
        }
        for (auto &[sz, arr] : bysize) {
            for (int i = 1; i < sz; i++) arr[i] += arr[i-1];
        }
        /*
        for (auto &[sz, arr] : bysize) {
            cerr << var(sz);
            for (auto x : arr) cerr << x <<  " ";
            cerr << endl;
        }
        */
    }
    for (int k = 1; k <= n; k++) {
        LL ans = 0;
        for (auto &[sz, arr] : bysize) {
            int r = sz / k * k;
            /*
            if (r > 0) debug(sz, k, r, arr[r-1]);
            else debug(sz, k, r);
            */
            if (r > 0) ans += arr[r-1];
        }
        cout << ans << " ";
    }
    cout << endl;
}
