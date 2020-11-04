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

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int vn, en;
int n1, n2, n3;
vector<vector<int>> graph;
vector<int> ccIdx;

void init()
{
    cin >> vn >> en;
    cin >> n1 >> n2 >> n3;
    graph.assign(vn, vector<int>());
    ccIdx.assign(vn, -1);
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

tuple<int,int> dfs(int u, vector<int> &color, int idx)
{
    ccIdx[u] = idx;
    int zero = 0, one = 0;
    for(auto v : graph[u])
    {
        if(color[v] == -1)
        {
            color[v] = 1 - color[u];
            auto [z, o] = dfs(v, color, idx);
            if(z == -1) return make_tuple(-1, -1);
            zero += z + (color[v] == 0);
            one += o + (color[v] == 1);
        }
        else if(color[v] == color[u]) return make_tuple(-1, -1);
    }
    return make_tuple(zero, one);
}

void run_dp(vector<vector<bool>> &dp, vector<vector<tuple<int,int>>> &bk, vector<tuple<int,int>> &cc)
{
    dp[0][0] = true;
    for(int i = 0; i < (int)cc.size(); i++)
        for(int j = 0; j <= n2; j++)
            if(dp[i][j])
            {
                auto [z, o] = cc[i];
                if(j+z <= n2) dp[i+1][j+z] = true, bk[i+1][j+z] = make_tuple(j, 0);
                if(j+o <= n2) dp[i+1][j+o] = true, bk[i+1][j+o] = make_tuple(j, 1);
            }
}

void print(vector<vector<tuple<int,int>>> &bk, vector<int> &color)
{
    vector<int> ans(vn, 0);
    vector<int> use_c2(bk.size()-1, false);
    for(int i = bk.size()-1, c2 = n2; i > 0; i--)
    {
        auto [go, col] = bk[i][c2];
        use_c2[i-1] = col;
        c2 = go;
    }
    for(int i = 0; i < vn; i++)
    {
        if(color[i] == use_c2[ccIdx[i]]) ans[i] = 2;
        else if(n1 > 0) ans[i] = 1, n1--;
        else ans[i] = 3;
    }

    cout << "YES" << endl;
    for(auto x : ans) cout << x;
    cout << endl;
}

void process()
{
    // bipartite check for each component
    vector<int> color(vn, -1);
    vector<tuple<int,int>> cc;
    bool bipartite = true;
    for(int i = 0; i < vn && bipartite; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 0;
            auto [z, o] = dfs(i, color, cc.size());
            if(z == -1) bipartite = false;
            cc.emplace_back(z+1, o);
        }
    }
    if(bipartite == false) 
    {
        cout << "NO" << endl; return;
    }
    vector<vector<bool>> dp(cc.size()+1, vector<bool>(n2+1, false));
    vector<vector<tuple<int,int>>> bk(cc.size()+1, vector<tuple<int,int>>(n2+1, make_tuple(-1, -1)));
    run_dp(dp, bk, cc);
    /*
    cerr << "DP = " << endl;
    for(auto r : dp)
    {
        for(auto c : r) cerr << c << " ";
        cerr << endl;
    }
    cerr << "BK = " << endl;
    for(auto r : bk)
    {
        for(auto [from, use] : r) cerr << "(" << from << "," << use << ") ";
        cerr << endl;
    }
    */
    if(dp.back().back() == false) cout << "NO" << endl;
    else print(bk, color);
}
