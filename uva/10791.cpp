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

LL n;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int caseN = 0;
    while (cin >> n && n) {
        cout << "Case " << ++caseN << ": ";
        process();
    }
    cout.flush();
    return 0;
}

constexpr int M = 1000006;
vector<LL> sp(M);
vector<LL> primes;

void init() {
    iota(range(sp), 0);
    for (LL i = 2; i < M; i++) {
        if (sp[i] == i) {
            primes.emplace_back(i);
            for (LL j = i*i; j < M; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
}

void process() {
    LL ans = 0;
    int is_prime = 0;
    for (auto p : primes) {
        if (n % p != 0) continue;
        is_prime += 1;
        LL tmp = 1;
        while (n % p == 0) tmp *= p, n /= p;
        ans += tmp;
    }
    if (n != 1) ans += n, is_prime += 1;
    if (is_prime == 0) ans = 2;
    else if (is_prime == 1) ans += 1;
    cout << ans << endl;
}

