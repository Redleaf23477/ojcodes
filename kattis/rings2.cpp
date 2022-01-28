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

int R, C;
char arr[102][102];
int ring[102][102];

void init() {
    cin >> R >> C;
    for (int i = 0; i < R+2; i++) {
        for (int j = 0; j < C+2; j++) {
            arr[i][j] = '.';
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i+1][j+1];
        }
    }
}

// O(N^3)
void process() {
    // init
    int max_r = 0;
    queue<tuple<int,int>> que;
    for (int i = 0; i < R+2; i++) {
        for (int j = 0; j < C+2; j++) {
            if (arr[i][j] == '.') {
                ring[i][j] = 0;
                que.emplace(i, j);
            } else {
                ring[i][j] = -1;
            }
        }
    }
    // bfs
    int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
    while (!que.empty()) {
        auto [i, j] = que.front(); que.pop();
        for (int d = 0; d < 4; d++) {
            int i2 = i + dr[d], j2 = j + dc[d];
            if (0 <= i2 && i2 < R+2 && 0 <= j2 && j2 < C+2) {
                if (ring[i2][j2] == -1) {
                    ring[i2][j2] = ring[i][j] + 1;
                    max_r = max(max_r, ring[i2][j2]);
                    que.emplace(i2, j2);
                }
            }
        }
    }
    // print
    int w = (max_r >= 10? 3 : 2);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (ring[i][j] == 0) {
                for (int i = 0; i < w; i++) cout << '.';
            } else {
                cout << setw(w) << setfill('.') << ring[i][j];
            }
        }
        cout << endl;
    }
}

