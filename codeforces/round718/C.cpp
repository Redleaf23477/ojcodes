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

void init() {
}

void process() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0)); {
        for (int i = 0; i < n; i++) cin >> arr[i][i];
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) arr[i][j] = -1;
    }
    function<bool(int,int)> valid = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    };
    function<void(int,int,int,int)> dfs = [&](int r, int c, int v, int dep=0) {
        // u, l, d, r
        debug(r, c, v, dep);
        if (dep == v) return;
        static int dr[] {-1, 0, 1, 0}, dc[] {0, -1, 0, 1};
        arr[r][c] = v;
        for (int i = 0; i < 4; i++) {
            int rr = r+dr[i], cc = c+dc[i];
            if (valid(rr, cc) && arr[rr][cc] == 0) {
                dfs(rr, cc, v, dep+1); break;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        dfs(i, i, arr[i][i], 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

