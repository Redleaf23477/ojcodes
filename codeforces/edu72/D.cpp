//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
using Edge = pair<ll,ll>;
#define v first
#define idx second

const int N = 5050;

int vn, en;
vector<Edge> graph[N];
vector<int> color;
vector<bool> vis, inStk;

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
    color.resize(en, 0);
    vis.resize(vn, false);
    inStk.resize(vn, false);
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].emplace_back(v, i);
    }
}

void dfs(int v)
{
    vis[v] = true;
    inStk[v] = true;
    for(auto p : graph[v])
    {
        auto c = p.first, idx = p.second;
        if(vis[c])
        {
            if(inStk[c]) color[idx] = 2;
            else color[idx] = 1;
            continue;
        }
        color[idx] = 1;
        dfs(c);
    }
    inStk[v] = false;
}

void process()
{
    for(int i = 0; i < vn; i++)
    {
        if(!vis[i]) dfs(i);
    }
    cout << *max_element(color.begin(), color.end()) << endl;
    for(auto x : color) cout << x << " ";
    cout << endl;
}

