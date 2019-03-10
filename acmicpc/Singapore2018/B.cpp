//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 500005;
int vn, en;
int vis[N];
vector<int> graph[N];

void init();
void process();

int32_t main()
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
    int u, v;
    for(int i = 0; i < en; i++)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

bool bipartite(int x, int col)
{
    vis[x] = col;
    bool isBip = true;
    for(auto c:graph[x])
    {
        if(vis[c] == 0)
        {
            isBip &= bipartite(c, 3-col);
        }
        else if(vis[c] == col)
        {
            isBip = false;
        }
    }
    return isBip;
}

void process()
{
    int ans = 0;
    bool allBip = true;
    for(int i = 1; i <= vn; i++)
    {
        if(vis[i]) continue;
        ans++;
        if(!bipartite(i, 1)) allBip = false;
    }
    cout << ans-1+allBip << endl;
}

