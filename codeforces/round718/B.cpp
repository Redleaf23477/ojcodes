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
    int n, m; cin >> n >> m;
    multiset<pair<int,int>> all;
    vector<multiset<int>> s(n); {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                s[i].insert(x);
            }
            all.insert(make_pair(*s[i].begin(), i));
        }
    }
    vector<vector<int>> ans(m); {
        for (int i = 0; i < m; i++) {
            auto [v, r] = *all.begin();
            for (int j = 0; j < n; j++) {
                if (j == r) {
                    ans[i].push_back(v);
                    s[j].erase(s[j].begin());
                } else {
                    auto it = s[j].end(); it--;
                    ans[i].push_back(*it);
                    s[j].erase(it);
                }
            }
            /*
            cerr << var(i) << " : ";
            for (auto x : ans[i]) cerr << x << " ";
            cerr << endl;
            */

            all.erase(all.begin());
            if (i != m-1) all.insert(make_pair(*s[r].begin(), r));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[j][i] << " ";
        }
        cout << endl;
    }
}

