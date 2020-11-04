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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

using Edge = tuple<LL, int>; // w, v
const LL INF = 1ll<<60;

struct Convex {
    vector<tuple<LL,LL>> arr; // a, b
    vector<int> prev;
    void push(LL a, LL b) {
        bool eq = false;
        while (prev.size() > 0 && prev.back() != -1) {
            auto [a2, b2] = arr.end()[-1];
            auto [a1, b1] = arr[prev.back()];
            __int128 u1 = b1-b, d1 = a-a1;
            __int128 u2 = b2-b, d2 = a-a2;
            if (u1*d2 > u2*d1) arr.pop_back(), prev.pop_back();
            else if (u1*d2 == u2*d1) { eq = true; break; } 
            else break;
        }
        if (prev.size() > 0 && prev.back() == -1) {
            auto [a1, b1] = arr.end()[-1];
            if (b < b1) arr.clear(), prev.clear();
            else if(b == b1) { eq = true; }
        }
        arr.emplace_back(a, b);
        prev.emplace_back(eq? prev.back() : prev.size()-1);

        /*
        cerr << "push(" << a << "," << b << "): " << endl;
        for (auto [x, y] : arr) cerr << x << " ";
        cerr << endl;
        for (auto p : prev) cerr << p << " ";
        cerr << endl;
        */
    }
};

int vn, en;
vector<vector<Edge>> graph;

void init() {
    cin >> vn >> en;
    graph.resize(vn);
    for (int i = 0; i < en; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }
}

void process() {
    vector<vector<LL>> path; // path[k-step][v] = min len
    vector<vector<vector<int>>> back; // backtrack of path
    path.assign(vn, vector<LL>(vn, INF));
    back.assign(vn, vector<vector<int>>(vn));
    // bellman ford
    path[0][0] = 0; back[0][0].emplace_back(0);
    for (int k = 0; k < vn-1; k++) {
        for (int u = 0; u < vn; u++) path[k+1][u] = path[k][u];
        for (int u = 0; u < vn; u++) {
            if (back[k][u].empty()) continue;
            for (auto [w, v] : graph[u]) {
                LL d = path[k][u] + w;
                if (d < path[k+1][v]) {
                    path[k+1][v] = d;
                    back[k+1][v] = vector<int>(1, u);
                } else if (d == path[k+1][v]) {
                    back[k+1][v].emplace_back(u);
                }
            }
        }
    }
    /*
    cerr << "path to " << vn-1 << " : " << endl;
    for (int k = 1; k < vn; k++) {
        cerr << var(k);
        if (back[k][vn-1] != -1) {
            cerr << path[k][vn-1] << " => ";
            for (int j = k, u = vn-1; u >= 0; u = back[j][u], j--) {
                cerr << u << " ";
            }
        }
        cerr << endl;
    }
    */
    // upper convex hull
    Convex upper;
    for (int k = vn-1; k > 0; k--) {
        if (back[k][vn-1].size() > 0) {
            upper.push(k, path[k][vn-1]);
        }
    }
    // mask
    auto arr = upper.arr;
    vector<bool> went(vn, false);
    function<void(int,int,vector<bool>&)> dfs = [&](int u, int k, vector<bool> &vis) {
        vis[u] = true, went[u] = true;
        if (k == 0) return;
        for (auto v : back[k][u]) {
            if (vis[v] == false) {
                dfs(v, k-1, vis);
            }
        }
    };
    for (auto [k, _] : arr) {
        vector<bool> vis(vn, false); 
        dfs(vn-1, k, vis);
    }
    vector<int> ans;
    for (int i = 0; i < vn; i++) {
        if (!went[i]) ans.emplace_back(i+1);
    }
    cout << ans.size() << endl;
    if (ans.size() > 0) {
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
}

