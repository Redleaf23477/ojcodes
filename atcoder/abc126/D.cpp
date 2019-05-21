//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, ll> Edge;
#define idx first
#define len second

const int N = 100005;

int vn;
vector<Edge> tree[N];

void init();
void process();

int32_t main()
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
    for(int i = 1; i < vn; i++)
    {
        int a, b; ll w; cin >> a >> b >> w;
        a--, b--;
        tree[a].emplace_back(b, w);
        tree[b].emplace_back(a, w);
    }
}

vector<bool> color;

void dfs(int idx, int pa)
{
    for(auto x:tree[idx])
    {
        if(x.idx == pa) continue;
        if(x.len%2 == 1) color[x.idx] = !color[idx];
        else color[x.idx] = color[idx];
        dfs(x.idx, idx);
    }
}

void process()
{
    color.resize(vn, false);
    dfs(0, 0);
    for(int i = 0; i < vn; i++)
        cout << (color[i]? '1' : '0') << endl;
}

