#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const int N = 200005;

int vn;
vector<int> color;
vector<int> tree[N], diff[N];
vector<int> ans;

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
    cin >> vn;
    color.resize(vn);
    ans.resize(vn, 0);
    for(auto &c : color) cin >> c;
    for(int i = 1; i < vn; i++)
    {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        diff[u].push_back(0);
        diff[v].push_back(0);
    }
}

int dfs1(int idx, int pa)
{
    int d = (color[idx] == 1)? 1 : -1;
    for(int i = 0; i < (int)tree[idx].size(); i++)
    {
        int x = tree[idx][i];
        if(x == pa) continue;
        diff[idx][i] = dfs1(x, idx);
        if(diff[idx][i] > 0) d += diff[idx][i];
    }
    return d;
}

void dfs2(int idx, int pa, int paw)
{
    ans[idx] = (color[idx] == 1)? 1 : -1;
    for(int i = 0; i < (int)tree[idx].size(); i++)
        if(tree[idx][i] == pa)
            diff[idx][i] = paw;
    for(auto x : diff[idx])
        ans[idx] += max(0, x);

    for(int i = 0; i < (int)tree[idx].size(); i++)
    {
        int x = tree[idx][i];
        if(x == pa) continue;
        if(diff[idx][i] > 0)
        {
            dfs2(x, idx, ans[idx]-diff[idx][i]);
        }
        else
        {
            dfs2(x, idx, ans[idx]);
        }
    }
}

void process()
{
    dfs1(0, 0);
    dfs2(0, 0, 0);
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

