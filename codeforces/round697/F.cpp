// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
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

using Mat = vector<vector<char>>;

int n;
// char m1[1002][1002], m2[1002][1002];
Mat m1, m2;
vector<vector<int>> graph;  // adjacency martix, [0,n): even row, [n, 2n): even col, [2n, 3n): odd row, [3n, 4n): odd col

void init() {
    cin >> n;
    // m1.resize(n, vector<char>(n)), m2.resize(n, vector<char>(n));
    m1.assign(n, vector<char>(n)), m2.assign(n, vector<char>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m1[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m2[i][j];
    graph.assign(4*n, vector<int>(4*n, 0));
}

void process() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (m1[i][j] == m2[i][j]) {
            // row(i) + col(j) = even
            graph[i][j+n] = 1; // even + even
            graph[j+n][i] = 1;
            graph[i+2*n][j+3*n] = 1; // odd + odd
            graph[j+3*n][i+2*n] = 1;
        } else {
            // row(i) + col(j) = odd
            graph[i][j+3*n] = 1; // even + odd
            graph[j+3*n][i] = 1;
            graph[i+2*n][j+n] = 1; // odd + even
            graph[j+n][i+2*n] = 1;
        }
    }
    /*
    for (int i = 0; i < 4*n; i++) {
        for (int j = 0; j < 4*n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    */
    function<bool(int, vector<bool>&)> dfs = [&](int u, vector<bool> &vis) -> bool {
        vis[u] = true;
        bool res = true;
        for (int v = 0; v < 4*n; v++) {
            if (graph[u][v] == 0) continue;
            if (v < 2*n && vis[v+2*n]) return false;
            if (v >= 2*n && vis[v-2*n]) return false;
            if (!vis[v]) res &= dfs(v, vis);
        }
        return res;
    };
    vector<bool> vis;
    bool good = dfs(0, vis = vector<bool>(4*n, false)) || dfs(n, vis = vector<bool>(4*n, false));
    cout << (good? "YES" : "NO") << endl;
}

