// O(n log^2 n), tle
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1000006;
int n, k, ans;
vector<int> G[N];

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
    cin >> n >> k;
    ans = 0;
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int dfs(int x, int fa)
{
    if(G[x].size() == 1) 
    {
        ans++;
        return 1;
    }
    vector<int> dist;
    for(auto c:G[x])
    {
        if(c == fa) continue;
        dist.push_back(dfs(c, x));
    }
    sort(dist.begin(), dist.end());
    while(dist.size() > 1)
    {
        int sz = dist.size();
        if(dist[sz-1] + dist[sz-2] <= k) 
        {
            ans -= sz-1;
            break;
        }
        dist.pop_back();
    }
    return dist.back()+1;
}


void process()
{
    for(int i = 0; i < n; i++)
    {
        if(G[i].size() == 1) continue;
        dfs(i, i);
        cout << ans << endl;
        break;
    }
}

