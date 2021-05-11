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

const int N = 2003;

int R, C;
LL w;
LL arr[N][N];

void init() {
    cin >> R >> C >> w;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        cin >> arr[r][c];
    }
}

bool legal(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

LL bfs(int r, int c, LL &ans) {
    const LL INF = 1ll<<60;
    int sr = R-1-r, sc = C-1-c;
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    vector<vector<LL>> dist(R, vector<LL>(C, INF));
    queue<pair<int,int>> Q;
    Q.emplace(r, c); vis[r][c] = true; dist[r][c] = 0;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
    LL dp = INF;
    if (arr[r][c] > 0) dp = arr[r][c];
    while (!Q.empty()) {
        tie(r, c) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int rr = r+dr[d], cc = c+dc[d];
            if (!legal(rr, cc) || vis[rr][cc] || arr[rr][cc] == -1) continue;
            dist[rr][cc] = min(dist[rr][cc], dist[r][c] + w);
            if (arr[rr][cc] != 0) dp = min(dp, arr[rr][cc] + dist[rr][cc]);
            vis[rr][cc] = true;
            Q.emplace(rr, cc);
        }
    }
    ans = (dist[sr][sc] == INF? -1 : dist[sr][sc]);
    return (dp == INF? -1 : dp);
}

void process() {
    LL ans = -1;
    LL d1 = bfs(0, 0, ans);
    LL d2 = bfs(R-1, C-1, ans);
    if (d1 != -1 && d2 != -1) d1 += d2;
    else d1 = -1;
    if (ans == -1) cout << d1 << endl;
    else if (d1 == -1) cout << ans << endl;
    else cout << min(ans, d1) << endl;
}

