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

const int N = 502, K = 21;
const LL INF = 1ll << 60;

int R, C, k;
LL dp[N][N][K];
LL go_r[N][N], go_d[N][N];

void init() {
    cin >> R >> C >> k;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C-1; j++) {
            cin >> go_r[i][j];
        }
    }
    for (int i = 0; i < R-1; i++) {
        for (int j = 0; j < C; j++) {
            cin >> go_d[i][j];
        }
    }
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) for (int s = 0; s < k; s++) {
        dp[i][j][k] = INF;
    }
    for (int i = 0; i < R; i++) dp[i][i][0] = 0;
}

void process() {
    function<bool(int,int)> legal = [](int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    };
    for (int s = 0; s <= k/2; s++) {
        for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
            int rr, cc;
            if (dp[r][c][s] != INF) {
                // go up
                rr = r-1, cc = c;
                if (legal(rr, cc)) {
                    dp[rr][cc][s+1] = min(dp[rr][cc][s+1], dp[r][c][s] + go_d[rr][cc]);
                }
                // go down
                rr = r+1, cc = c;
                if (legal(rr, cc)) {
                    dp[rr][cc][s+1] = min(dp[rr][cc][s+1], dp[r][c][s] + go_d[r][c]);
                }
                // go left
                rr = r, cc = c-1;
                if (legal(rr, cc)) {
                    dp[rr][cc][s+1] = min(dp[rr][cc][s+1], dp[r][c][s] + go_r[rr][cc]);
                }
                // go right
                rr = r, cc = c+1;
                if (legal(rr, cc)) {
                    dp[rr][cc][s+1] = min(dp[rr][cc][s+1], dp[r][c][s] + go_r[r][c]);
                }
            }
        }
    }
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
    }
}

