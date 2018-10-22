//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 85;
int vn, rpos, hpos, mpos;
vector<int> G[N];
int fa[N];

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
    cin >> vn >> rpos >> hpos >> mpos;
    for(int i = 1; i < vn; i++)
    {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void buildTree() // point to father
{
    vector<int> deg(vn+1);
    vector<bool> vis(vn+1, false);
    queue<int> leaf;
    for(int i = 1; i <= vn; i++) 
    {
        deg[i] = G[i].size();
        if(deg[i] == 1) leaf.push(i);
    }
    while(!leaf.empty())
    {
        int f = leaf.front(); leaf.pop();
        for(auto c:G[f])
        {
            if(vis[c]) continue;
            vis[f] = true;
            fa[f] = c;
            if(--deg[c] == 1) leaf.push(c);
        }
    }
}

void process()
{
    buildTree();
//    for(int i = 1; i <= vn; i++) cout << "fa[" << i << "] = " << fa[i] << endl;
    int cnt = 0;
    for(int pos = rpos; fa[pos] != 0 && fa[pos] != hpos && fa[pos] != mpos; pos = fa[pos], cnt++);
    cout << cnt+1 << endl;
}

