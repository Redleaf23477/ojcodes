//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

int vn, en;
vector<int> graph[N];
vector<int> color;
int color_cnt[4];
vector<bool> checkVis;

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
    color.resize(vn, 0);
    checkVis.resize(vn, false);
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

bool dfs_color(int v, int col)
{
    color[v] = col; color_cnt[col]++;
    checkVis[v] = true;
    vector<int> vis(vn, 0);
    for(auto c : graph[v])
    {
        vis[c] = true;
        checkVis[c] = true;
    }
    for(int i = 0; i < vn; i++)
    {
        if(vis[i] == false) 
        {
            if(color[i] == 0) color[i] = col, color_cnt[col]++;
            else if(color[i] != col) return false;
        }
        else if(color[i] == col) return false;
    }
    for(auto c : graph[v])
    {
        if(color[c] == 0) 
        {
            if(col == 3) return false;
            if(dfs_color(c, col+1) == false) return false;
        }
        else if(color[c] == col) return false;
    }
    return true;
}

void process()
{
    bool ok = dfs_color(0, 1);
    for(int i = 0; i < vn && ok; i++)
    {
        if(graph[i].size() != vn - color_cnt[color[i]]) ok = false;
        for(auto c : graph[i]) if(color[i] == color[c]) { ok = false; break; }
        if(checkVis[i] == false) ok = false;
    }
    if(color_cnt[1] == 0 || color_cnt[2] == 0 || color_cnt[3] == 0) ok = false;
    if(ok) 
    {
        for(auto c : color) cout << c << " ";
        cout << endl;
    }
    else cout << -1 << endl;
}

