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
using LL = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, h;
vector<vector<int>> tree;
vector<int> leaf;

void dfs(int u, int pa)
{
    if(tree[u].size() == 1) leaf.emplace_back(u);
    for(auto v : tree[u])
    {
        if(v == pa) continue;
        dfs(v, u);
    }
}

void init()
{
    cin >> n >> h;
    tree.resize(n);
    for(int i = 1; i < n; i++) 
    {
        int u, v; cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    dfs(h, h);
}

void process()
{
    vector<tuple<int,int>> ans;
    int t = leaf.size();
    for(int i = t/2-1, j = t-1; i >= 0; i--, j--)
    {
        ans.emplace_back(leaf[i], leaf[j]);
    }
    if(t%2 == 1) ans.emplace_back(leaf[t/2], h);

    cout << ans.size() << endl;
    for(auto [u, v] : ans) cout << u << " " << v << endl;
}

