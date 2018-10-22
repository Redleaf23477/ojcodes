#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Edge;
#define idx first
#define w second
#define endl '\n'

struct KEdge { ll from, to, w; };

bool cmpW (const KEdge &a, const KEdge &b)
{
    return a.w < b.w;
}

struct Disjointset
{
    static const int MAXN = 200005;
    int vn, pa[MAXN];
    Disjointset(int vn):vn(vn)
    {
        init();
    }
    void init()
    {
        for(int i = 0; i < vn; i++) pa[i] = i;
    }
    int findrt(int idx)
    {
        if(pa[idx] == idx) return idx;
        else return pa[idx] = findrt(pa[idx]);
    }
    bool same(int a, int b)
    {
        return findrt(a) == findrt(b);
    }
    void uni(int a, int b)
    {
        pa[findrt(a)] = findrt(b);
    }
};

const int EN = 200000;
const int VN = 100000;
const int MAX_LOG = 18;

int vn, en;
ll mstTot;
KEdge edges[EN+5];
map<P, ll> edgeLen;
vector<Edge> mst[VN+1];
int pa[MAX_LOG+1][VN+5];
ll dp[MAX_LOG+1][VN+5];
int dep[VN+5];
vector<Edge> G[VN+5];

void init();
void process();

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

ll kruskal()
{
    ll tot = 0;
    sort(edges, edges+en, cmpW);
    Disjointset ds(vn+1);
    for(int i = 0, cnt = 0; i < en && cnt < vn-1; i++)
    {
        if(ds.same(edges[i].from, edges[i].to)) continue;
        ll f = edges[i].from, t = edges[i].to, w = edges[i].w;
        tot += w;
        ds.uni(f, t);
        mst[f].emplace_back(t, w);
        mst[t].emplace_back(f, w);
    }
    return tot;
}

void dfsMst(int idx, int fa)
{
    for(auto c:mst[idx])
    {
        if(c.idx == fa) continue;
        G[idx].emplace_back(c);
        dfsMst(c.idx, idx);
    }
}

void dfs(int x, int p, ll w)  // w = dist(p, x)
{
    if(p == -1) 
    {
        dep[x] = 0;
        dp[0][x] = 0;
    }
    pa[0][x] = p;
    dp[0][x] = w;
    for(auto c:G[x])
    {
        dep[c.idx] = dep[x]+1;
        dfs(c.idx, x, c.w);
    }
}

void build_lca_dp()
{
    for(int i = 0; i < MAX_LOG; i++)
    {
        for(int x = 1; x <= vn; x++)
        {
            if(pa[i][x] == -1) 
            {
                pa[i+1][x] = -1;
                dp[i+1][x] = dp[i][x];
            }
            else 
            {
                pa[i+1][x] = pa[i][pa[i][x]];
                dp[i+1][x] = max(dp[i][x], dp[i][pa[i][x]]);
            }
        }
    }
}

inline pair<int, ll> jump(int x, int d)
{
    ll mxedge = 0;
    for(int i = 0; i < MAX_LOG; i++)
    {
        if( (d>>i)&1 ) mxedge = max(mxedge, dp[i][x]), x = pa[i][x];
    }
    return make_pair(x, mxedge);
}

inline ll find_lca(int a, int b)
{
    ll mxedge = 0;
    if(dep[a]>dep[b]) swap(a, b);
    tie(b, mxedge) = jump(b, dep[b]-dep[a]);
    if(a == b) return mxedge;
    for(int i = MAX_LOG-1; i >= 0; i--)
    {
        if(pa[i][a] != pa[i][b])
        {
            mxedge = max(mxedge, dp[i][a]);
            a = pa[i][a];
            mxedge = max(mxedge, dp[i][b]);
            b = pa[i][b];
        }
    }
    return max({ mxedge, dp[0][a], dp[0][b] });  // lca = pa[0][a]
}

void printG()
{
    for(int i = 1; i <= vn; i++)
    {
        cout << i << " : ";
        for(auto c:G[i]) cout << "(" << c.idx << "," << c.w << ")";
        cout << endl;
    }
}

void init()
{
    cin >> vn >> en;
    for(int i = 0; i < en; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
        edgeLen[P(min(edges[i].from, edges[i].to), max(edges[i].from, edges[i].to))] = edges[i].w;
    }
    mstTot = kruskal();
    // to rooted tree
    dfsMst(1, -1);
    // preBuild lca
    dfs(1, -1, 0);
    build_lca_dp();
}

void process()
{
    int q; cin >> q;
    while(q--)
    {
        int from, to; cin >> from >> to;
        ll wAdd = edgeLen[P(min(from, to), max(from, to))];
//        cout << "mxedge = " << find_lca(from, to) << endl;
        cout << mstTot + wAdd - find_lca(from, to) << endl;
    }
}
