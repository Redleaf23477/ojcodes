// O(n log^2 n), tle
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1000006;
int n, k;
vector<int> G[N];
multiset<int> leafSet[N];

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
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int x, int dep, int fa)
{
    // leaf
    if(G[x].size() == 1) 
    {
        leafSet[x].insert(dep);
        return;
    }
    // switch to largest multiset (dsu on multiset)
    int bigIdx = x;
    for(auto c:G[x])
    {
        if(c == fa) continue;
        dfs(c, dep+1, x);
        if(leafSet[c].size() > leafSet[bigIdx].size()) bigIdx = c;
    }
    leafSet[x] = leafSet[bigIdx], leafSet[bigIdx].clear();
    // merge multiset
    for(auto c:G[x])
    {
        if(c == fa || c == bigIdx) continue;
        for(auto d:leafSet[c])
        {
            int mxDist = k + 2*dep - d;
            auto ub = leafSet[x].upper_bound(mxDist);
            if(ub == leafSet[x].begin()) // cannot merge, add to leafSet
            {
                leafSet[x].insert(d);
            }
            else // merge d into the biggest mergeable set of leaf
            {
                ub--;
                if(*ub < d)
                {
                    leafSet[x].erase(ub);
                    leafSet[x].insert(d);
                }
            }
        }
    }
}


void process()
{
    for(int i = 0; i < n; i++)
    {
        if(G[i].size() == 1) continue;
        dfs(i, 0, i);
        cout << leafSet[i].size() << endl;
        break;
    }
}

