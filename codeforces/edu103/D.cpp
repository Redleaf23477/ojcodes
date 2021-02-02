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

int vn, n;
vector<vector<int>> graph;

void init() {
    cin >> n; n = n+1; vn = 2*n;
    string str; cin >> str;
    // [0, n) even, [n, 2*n) odd
    graph.assign(vn, vector<int>());
    for (int i = 0; i < n; i++) {
        if (i < n-1 && str[i] == 'R') graph[i].emplace_back(i+1+n);
        if (i-1 >= 0 && str[i-1] == 'L') graph[i].emplace_back(i-1+n);
        if (i < n-1 && str[i] == 'L') graph[i+n].emplace_back(i+1);
        if (i-1 >= 0 && str[i-1] == 'R') graph[i+n].emplace_back(i-1);
    }
}

void process() {
    vector<int> vis(2*n, -1);
    vector<int> cc;
    function<int(int,int)> dfs = [&](int u, int label) -> int {
        vis[u] = label;
        int cnt = 1;
        for (auto v : graph[u]) {
            if (vis[v] != -1) { assert(vis[v] == label); continue; }
            cnt += dfs(v, label);
        }
        return cnt;
    };
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            int cnt = dfs(i, cc.size());
            cc.emplace_back(cnt);
        }
        cout << cc[vis[i]] << " ";
    }
    cout << endl;
}

