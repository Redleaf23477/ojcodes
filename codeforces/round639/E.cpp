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
using ll = long long int;

const int N = 200005;

int n, m;
vector<int> graph[N], indeg;
vector<int> revGraph[N], revIndeg;
vector<bool> vis, instk;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> m;
    indeg.resize(n+1, 0);
    revIndeg.resize(n+1, 0);
    vis.resize(n+1, false);
    instk.resize(n+1, false);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
        revGraph[v].push_back(u);
        revIndeg[u]++;
    }
}

bool cycCheck(int u)
{
    if(instk[u] == true) return true;
    vis[u] = true;
    instk[u] = true;
    bool res = false;
    for(auto v : graph[u])
    {
        res |= cycCheck(v);
    }
    instk[u] = false;
    return res;
}

void run(int &ans, vector<char> &way, vector<int> (&g)[N], vector<int> &in)
{
    const int INF = 2*n;
    vector<int> dp(n+1, INF);
    // deal with unused
    for(int i = 1; i <= n; i++)
    {
        if(g[i].size() == 0 && in[i] == 0)
            way[i] = 'A', in[i] = -1, ans++;
    }
    // topology sort order dp
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in[i] == 0) 
        {
            dp[i] = i;
            q.push(i);
        }
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(g[u].size() == 0)
        {
            if(u < dp[u]) way[u] = 'A', ans++;
            else way[u] = 'E';
        }
        else
        {
            way[u] = 'E';
        }
        for(auto v : g[u])
        {
            dp[v] = min(dp[v], dp[u]);
            if(--in[v] == 0) q.push(v);
        }
    }
}

void process()
{
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == false)
            if(cycCheck(i) == true)
            {
                cout << -1 << endl; return;
            }
    }
    int ans1 = 0, ans2 = 0;
    vector<char> way1(n+1), way2(n+1);
    run(ans1, way1, graph, indeg);
    run(ans2, way2, revGraph, revIndeg);
    if(ans1 > ans2)
    {
        cout << ans1 << endl;
        for(int i = 1; i <= n; i++) cout << way1[i];
        cout << endl;
    }
    else
    {
        cout << ans2 << endl;
        for(int i = 1; i <= n; i++) cout << way2[i];
        cout << endl;
    }
}

