//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 200005;
const ll INF = (1ll<<60);
int n;
int dist[N], father[N];
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
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int x, int pa)
{
    dist[x] = dist[pa]+1;
    father[x] = pa;
    for(auto c:G[x])
    {
        if(c == pa) continue;
        dfs(c, x);
    }
}

bool cmp(int a, int b)
{
    return dist[a] > dist[b];
}

void process()
{
    dist[0] = -1;
    dfs(1, 0);
    vector<int> pt(n+1);
    for(int i = 0; i < n+1; i++) pt[i] = i;
    sort(pt.begin(), pt.end(), cmp);
    int ans = 0;
    for(int i = 0; i <= n; i++)
    {
        int x = pt[i];
        if(dist[x] > 2)
        {
            dist[father[x]] = 1;
            ans++;
            for(auto c:G[father[x]]) dist[c] = min(dist[c], 2);
        }
    }
    cout << ans << endl;
}

