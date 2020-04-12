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

int n, q;
vector<int> tree[N];
vector<int> tin, tout, pa, dep;

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

void dfs(int u, int p, int d)
{
    static int t = 0;
    pa[u] = p;
    dep[u] = d;
    tin[u] = ++t;
    for(auto c : tree[u])
    {
        if(c == p) continue;
        dfs(c, u, d+1);
    }
    tout[u] = ++t;
}

void init()
{
    cin >> n >> q;
    tin.resize(n+1, 0);
    tout.resize(n+1, 0);
    pa.resize(n+1, 0);
    dep.resize(n+1, 0);
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    dfs(1, 1, 1);
    /*
    cerr << "check tree: " << endl;
    for(int i = 0; i < n; i++)
    {
        cerr << var(i) << var(tin[i]) << var(tout[i]) << var(dep[i]) << endl;
    }
    */
}

void process()
{
    while(q--)
    {
        int len; cin >> len;
        vector<int> qry(len);
        int mxDepNode = 0;
        for(auto &x : qry) 
        {
            cin >> x;
            if(mxDepNode == 0 || dep[x] > dep[mxDepNode])
                mxDepNode = x;
        }
        bool good = true;
        for(auto x : qry)
        {
            if(x == mxDepNode) continue;
            x = pa[x];
            if(!(tin[x] <= tin[mxDepNode] && tout[x] >= tout[mxDepNode])) good = false;
        }
        if(good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

