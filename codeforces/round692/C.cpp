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

using P = tuple<int,int>;
int n, m;
vector<P> arr;

void init() {
    cin >> n >> m;
    arr.resize(m);
    for (int i = 0; i < m; i++) {
        int r, c; cin >> r >> c;
        arr[i] = make_tuple(r-1, c-1);
    }
}

void process() {
    vector<int> R(n, -1);
    vector<vector<int>> graph(m);
    int ans = m;
    for (int i = 0; i < m; i++) {
        if (get<0>(arr[i]) == get<1>(arr[i])) { 
            ans--;
            continue;
        }
        R[get<0>(arr[i])] = i;
    }
    for (int i = 0; i < m; i++) {
        if (get<0>(arr[i]) == get<1>(arr[i])) continue;
        int j = R[get<1>(arr[i])];
        if (j != -1) {
            graph[i].emplace_back(j);
            graph[j].emplace_back(i);
        }
    }
    vector<bool> vis(m, false);
    function<bool(int,int)> dfs = [&](int u, int p) -> bool {
        vis[u] = true;
        bool res = false;
        for (auto v : graph[u]) {
            if (v == p) continue;
            if (vis[v]) return true;
            res |= dfs(v, u);
        }
        return res;
    };
    for (int i = 0; i < m; i++) {
        if (!vis[i]) ans += dfs(i, i);
    }
    cout << ans << endl;
}

