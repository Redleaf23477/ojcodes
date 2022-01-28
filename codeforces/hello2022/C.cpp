// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
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
void solve();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    cout.flush();
    return 0;
}

void init() {
}

int query(int n) {
    cout << "? " << n << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void report(vector<int> &arr) {
    cout << "!";
    for (int i = 1; i < (int)arr.size(); i++) cout << " " << arr[i];
    cout << endl;
    cout.flush();
}

void solve() {
    int n; cin >> n;
    vector<int> p(n+1, -1);
    int vis_cnt = 0;
    vector<int> vis(n+1, 0);
    auto shift = [](vector<int> &tmp, int front) {
        vector<int> ans(tmp.size());
        int idx = (find(range(tmp), front) - tmp.begin() + 1) % tmp.size();
        int j = 0;
        for (int i = idx; i < tmp.size(); i++) ans[j++] = tmp[i];
        for (int i = 0; i < idx; i++) ans[j++] = tmp[i];
        tmp = ans;
    };
    auto run = [&](vector<int> &arr, int qidx) {
        for (int i = 0; i < arr.size(); i++) {
            int ans = arr[i];
            for (int j = i+1, pos = qidx; j > 0; j--) {
                if (j == 1) p[pos] = ans;
                else pos = p[pos];
            }
        }
    };
    for (int qidx = 1; qidx <= n && vis_cnt != n; qidx++) {
        if (vis[qidx]) continue;
        vector<int> tmp;
        for (int c = 0; c < n; c++) {
            int ans = query(qidx);
            vis[ans] += 1;
            if (vis[ans] == 2) break;
            tmp.emplace_back(ans);
            vis_cnt += 1;
        }
        shift(tmp, qidx);
        run(tmp, qidx);
    }
    report(p);
}

