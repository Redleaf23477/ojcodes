#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Edge = pair<ll,ll>;
#define u first
#define v second
const ll INF = 1e16+16;
#define endl '\n'

struct DisjointSet
{
    int sz;
    vector<int> pa;
    void init(int n)
    {
        sz = n;
        pa.resize(n);
        for(int i = 0; i < n; i++) pa[i] = i;
    }
    int findrt(int x)
    {
        if(pa[x] == x) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y)
    {
        return findrt(x) == findrt(y);
    }
    bool uni(int x, int y)
    {
        x = findrt(x), y = findrt(y);
        if(x == y) return false;
        pa[x] = y;
        return true;
    }
};

int en, vn;
vector<Edge> edge;
vector<int> deg;
DisjointSet ds;
map<int,int> remp;

void init()
{
    cin >> en;
    edge.resize(en);
    remp.clear();
    int idx = 0;
    map<int,int> mp;
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v;
        if(mp.count(u) == 0) mp[u] = idx, remp[idx] = u, idx++;
        if(mp.count(v) == 0) mp[v] = idx, remp[idx] = v, idx++;
        edge[i] = make_pair(mp[u], mp[v]);
    }
    vn = idx;
    ds.init(vn);
    deg.resize(vn); fill(deg.begin(), deg.end(), 0);
    for(int i = 0; i < en; i++)
    {
        deg[edge[i].u]++, deg[edge[i].v]++;
    }
}

void process()
{
    vector<int> cycBuff, leafBuff;
    vector<vector<int>> cycEdge, leafEdge;
    cycEdge.resize(vn), leafEdge.resize(vn);
    for(int i = 0; i < en; i++)
    {
        if(ds.uni(edge[i].u, edge[i].v) == false)
            cycBuff.emplace_back(i);
        if(deg[edge[i].u] == 1 || deg[edge[i].v] == 1)
            leafBuff.emplace_back(i);
    }
    for(auto idx : cycBuff)
        cycEdge[ds.findrt(edge[idx].u)].emplace_back(idx);
    for(auto idx : leafBuff)
    {
        int leaf = (deg[edge[idx].u] == 1)? edge[idx].u : edge[idx].v;
        leafEdge[ds.findrt(leaf)].emplace_back(idx);
    }
    vector<tuple<int,int,int>> ans;
    vector<bool> vis(vn, false);
    vis[ds.findrt(0)] = true;
    for(int i = 1; i < vn; i++)
    {
        int pa = ds.findrt(i);
        if(vis[pa]) continue;
        vis[pa] = true;
        if(cycEdge[pa].size() != 0)
        {
            int idx = cycEdge[pa].front();
            ans.emplace_back(idx, edge[idx].u, 0);
        }
        else if(leafEdge[pa].size() != 0)
        {
            int idx = leafEdge[pa].front();
            int leaf = (deg[edge[idx].u] == 1? edge[idx].u : edge[idx].v);
            ans.emplace_back(idx, leaf, 0);
        }
        else cout << "WAAAAAA" << pa << endl;
    }
    cout << ans.size() << endl;
    for(auto tup : ans)
    {
        int idx, u, v;
        tie(idx, u, v) = tup;
        cout << idx+1 << " " << remp[u] << " " << remp[v] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
}
