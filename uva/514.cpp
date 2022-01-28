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

bool ok(vector<int> &to) {
    vector<int> from(to.size());
    iota(from.begin(), from.end(), 1);
    stack<int> stk;
    int i = 0, j = 0;
    while (j < to.size()) {
        if (i < from.size() && from[i] == to[j]) { 
            i++, j++;
        } else if (!stk.empty() && stk.top() == to[j]) {
            stk.pop();
            j++;
        } else {
            while (i < from.size() && from[i] != to[j]) {
                stk.emplace(from[i]);
                i++;
            }
            if (i == from.size()) {
                return false;
            } else {
                i++, j++;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while (cin >> n && n != 0) {
        vector<int> to(n);
        while (true) {
            // input to
            cin >> to[0];
            if (to[0] == 0) {
                cout << endl;
                break;
            } else {
                for (int i = 1; i < n; i++) cin >> to[i];
                if (ok(to)) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    cout.flush();
    return 0;
}

void init() {
}

void process() {
}

