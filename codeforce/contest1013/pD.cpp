//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 2*200005;

int R, C, vn, en;
vector<int> graph[N];
bool vis[N];

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
    cin >> R >> C >> en;
    vn = R+C;
    for(int i = 0; i < en; i++)
    {
        int r, c, u, v; cin >> r >> c; r--, c--;
        u = r, v = R+c;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int idx)
{
    vis[idx] = true;
    for(auto c:graph[idx])
    {
        if(!vis[c]) dfs(c);
    }
}

void process()
{
    int cnt = 0;
    for(int i = 0; i < vn; i++)
    {
        if(!vis[i]) 
        {
//            cout << i << endl;
            cnt++, dfs(i);
        }
    }
    cout << cnt-1 << endl;
}

