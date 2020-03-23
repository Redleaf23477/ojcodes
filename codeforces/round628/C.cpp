// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;
using Edge = pair<int,int>;

int n, leafN;
vector<Edge> tree;
vector<bool> leaves;

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
    leafN = 0;
    vector<int> cnt(n+1, 0);
    leaves.resize(n+1, false);
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        tree.emplace_back(u, v);
        cnt[u]++, cnt[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 1) leaves[i] = true, leafN++;
    }
}

void process()
{
    vector<int> ans(tree.size(), -1);
    if(leafN == 2)
    {
        for(int i = 0; i < (int)ans.size(); i++) ans[i] = i;
    }
    else
    {
        for(int i = 0, idx = 0; i < (int)tree.size() && idx < 3; i++)
        {
            if(leaves[tree[i].first] || leaves[tree[i].second])
            {
                ans[i] = idx++;
            }
        }
        for(int i = 0, idx = 3; i < (int)tree.size(); i++)
        {
            if(ans[i] == -1) ans[i] = idx++;
        }
    }
    for(auto x : ans) cout << x << endl;
}

