// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

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

int n;
vector<double> p;
vector<tuple<int,int>> edge;
vector<int> pa;

void dfs(int u, int p, vector<vector<int>> &tree)
{
    pa[u] = p;
    for(auto v : tree[u])
    {
        if(v == p) continue;
        dfs(v, u, tree);
    }
}

void init()
{
    cin >> n;
    p.assign(n+1, 0); for(int i = 0; i < n; i++) { cin >> p[i]; p[i] = 1 - p[i]; }
    pa.assign(n+1, n);
    vector<vector<int>> tree(n);
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        edge.emplace_back(u, v);
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    dfs(0, n, tree);
}

void process()
{
    double vsum = 0; for(int i = 0; i < n; i++) vsum += p[i];
    double esum = 0; for(auto [x, y] : edge) esum += p[x] * p[y];

    vector<double> csum(n+1, 0);
    for(int i = 1; i < n; i++) csum[pa[i]] += p[i];


    int q; cin >> q;
    while(q--)
    {
        int v; double np; cin >> v >> np; np = 1 - np;

        vsum -= p[v];
        esum -= p[v] * csum[v];
        esum -= p[pa[v]] * csum[pa[v]];

        csum[pa[v]] = csum[pa[v]] - p[v] + np;
        p[v] = np;
        
        vsum += p[v];
        esum += p[v] * csum[v];
        esum += p[pa[v]] * csum[pa[v]];

        cout << fixed << setprecision(6) << vsum - esum << endl;
    }
}

