// by redleaf23477
// small
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
using ll = long long int;
using P = pair<ll,ll>;
#define t first
#define idx second

const int N = 110;

ll vn, en;
vector<P> ord;
vector<P> edge;
vector<int> rk;
vector<vector<int>> graph;
ll mat[N][N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> vn >> en;
    graph.clear();
    graph.resize(vn);
    ord.resize(vn);
    rk.resize(vn);
    edge.clear();
    ord[0] = P(0, 0);
    rk[0] = 0;
    for(int i = 1; i < vn; i++)
    {
        cin >> ord[i].t;
        ord[i].t = -ord[i].t;
        ord[i].idx = i;
        rk[i] = ord[i].t;
    }
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        edge.emplace_back(u, v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < vn; i++)
        for(int j = 0; j < vn; j++)
            mat[i][j] = 1000000;
}

void process()
{
    // i-th => time = 100*i
    // bfs
    queue<int> q;
    q.push(0);
    vector<bool> vis(vn, 0);
    vis[0] = true;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(auto v:graph[u])
        {
            if(vis[v])
            {
                continue;
            }
            if(rk[u] < rk[v])
            {
                mat[min(u,v)][max(u,v)] = 100*rk[v] - 100*rk[u];
                q.push(v); vis[v] = true;
            }
        }
    }
    // print
    for(auto e : edge)
    {
        cout << mat[e.first][e.second] << " ";
    }
    cout << endl;
}

