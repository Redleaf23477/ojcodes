//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 10;

int vn, en;
vector<pair<int,int>> graph;
#define u first
#define v second

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
    cin >> vn >> en;
    graph.resize(en);
    for(int i = 0; i < en; i++)
    {
        cin >> graph[i].u >> graph[i].v;
    }
}

int stk[10];

ll runGraph()
{
    ll cnt = 0;
    bool avail[10][10];
    memset(avail, 0, sizeof(avail));
    for(int i = 1; i <= 6; i++)
        for(int j = i; j <= 6; j++)
            avail[i][j] = true;
    for(auto e : graph)
    {
        int from = stk[e.u], to = stk[e.v];
        if(avail[from][to] || avail[to][from])
        {
            avail[from][to] = avail[to][from] = false;
            cnt++;
        }
    }
    return cnt;
}

ll dfs(int v)
{
    if(v == vn+1) return runGraph();
    ll ans = 0;
    for(int idx = 1; idx <= 6; idx++)
    {
        stk[v] = idx;
        ans = max(ans, dfs(v+1));
    }
    return ans;
}

void process()
{
    cout << dfs(1) << endl;
}

