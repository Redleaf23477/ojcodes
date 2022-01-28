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

constexpr int N = 50 + 1;
constexpr int INF = 2*N;

int n;
char maze[N][N];
int cnt[N][N];

void init() {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> maze[i][j];
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + (maze[i][j] == '#');
    }
    /*
    cerr << "debug = ";
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cerr << cnt[i][j] << " \n"[j == n-1];
    }
    */
}

int dp[N][N][N][N];

int area(int r0, int c0, int r1, int c1) {
    return cnt[r1][c1] - cnt[r1][c0-1] - cnt[r0-1][c1] + cnt[r0-1][c0-1];
}

int f(int r0, int c0, int r1, int c1) {
    int R = r1 - r0 + 1, C = c1 - c0 + 1;

    if (R == 0 || C == 0) return 0;

    auto &ans = dp[r0][c0][r1][c1];
    if (ans != INF) return ans;

    // op1: cover the whole rectangle, do nothing if available
    if (area(r0, c0, r1, c1) == 0) {
        return ans = 0;
    } else {
        ans = min(ans, max(R, C));
    }

    // op2: divide 
    int tmp = max(R, C);
    for (int len = 0; len < tmp; len++) {
        int rm = min(r0 + len - 1, r1 - 1), cm = min(c0 + len - 1, c1 - 1), op;
        // op1: horizontal
        op = f(r0, c0, rm, c1);
        op += f(rm+1, c0, r1, c1);
        ans = min(ans, op);
        // op2: vertical
        op = f(r0, c0, r1, cm);
        op += f(r0, cm+1, r1, c1);
        ans = min(ans, op);
    }

    return ans;
}

void process() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++) for (int l = 0; l < N; l++) {
            dp[i][j][k][l] = INF;
        }
    cout << f(1, 1, n, n) << endl;
}

