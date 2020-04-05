// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const int N = 200005;

int vn, en, sn;
set<int> special;
vector<int> graph[N];
vector<int> level;

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
    cin >> vn >> en >> sn;
    level.resize(vn, -1);
    for(int i = 0; i < sn; i++)
    {
        int x; cin >> x; 
        special.insert(x-1);
    }
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(int u)
{
    queue<int> q;
    q.emplace(u);
    level[u] = 0;
    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(auto v : graph[u])
        {
            if(level[v] != -1) continue;
            level[v] = level[u]+1;
            q.emplace(v);
        }
    }
    /*
    cerr << "check level" << endl;
    for(int i = 0; i < vn; i++)
        cerr << var(i) << var(level[i]) << endl;
    */
}

void process()
{
    bfs(0);
    vector<int> splv;
    for(auto x : special)
        splv.push_back(level[x]);
    sort(splv.begin(), splv.end());
    int mn = vn;
    for(int i = 1; i < (int)splv.size(); i++)
        mn = min(mn, splv[i]-splv[i-1]);
    for(auto x : special)
    {
        for(auto v : graph[x])
            if(special.count(v) != 0)
                mn = 0;
    }
    if(mn == 0) cout << level[vn-1] << endl;
    else cout << level[vn-1]-mn+1 << endl;
}

