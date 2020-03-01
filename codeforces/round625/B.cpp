// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const int N = 200005;
const int INF = 1<<30;

int vn, en, pn;
vector<int> graph[N], rev[N];
vector<int> path;
vector<int> dist;

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

void bfs(int u)
{
    dist[u] = 0;
    queue<int> q; q.emplace(u);
    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(auto v : rev[u])
        {
            if(dist[v] == INF)
            {
                dist[v] = dist[u]+1;
                q.emplace(v);
            }
        }
    }
    /*
    cerr << "dist from " << path.back() << " : ";
    for(auto u : dist) cerr << u << " ";
    cerr << endl;
    */
}

void init()
{
    cin >> vn >> en;
    dist.resize(vn, INF);
    for(int e = 0; e < en; e++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].emplace_back(v);
        rev[v].emplace_back(u);
    }
    cin >> pn;
    path.resize(pn);
    for(auto &p : path) 
    {
        cin >> p; p--;
    }
    bfs(path.back());
}

void process()
{
    int ans_mx = 0, ans_mn = 0;
    for(int i = 1; i < pn; i++)
    {
        int u = path[i-1], v = path[i];
        int mn = INF, mnCnt = 0, cur = dist[v];
        for(auto w : graph[u])
        {
            if(dist[w] < mn) mn = dist[w], mnCnt = 1;
            else if(dist[w] == mn) mnCnt++;
        }
        if(cur != mn) ans_mn++, ans_mx++;
        else if(mnCnt > 1) ans_mx++;
    }
    cout << ans_mn << " " << ans_mx << endl;
}

