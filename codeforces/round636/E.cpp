// by redleaf23477
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

const int N = 200005;

int vn, en;
int a, b, c;
vector<ll> w;
vector<int> dist_a, dist_b, dist_c;
vector<int> graph[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> vn >> en;
    w.resize(en+1, 0);
    dist_a.resize(vn); fill(dist_a.begin(), dist_a.end(), 0);
    dist_b.resize(vn); fill(dist_b.begin(), dist_b.end(), 0);
    dist_c.resize(vn); fill(dist_c.begin(), dist_c.end(), 0);
    cin >> a >> b >> c; a--, b--, c--;
    for(int i = 0; i < vn; i++) graph[i].clear();
    for(int i = 1; i <= en; i++) cin >> w[i];
    sort(w.begin(), w.end());
    for(int i = 1; i <= en; i++) w[i] += w[i-1];
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(int u, vector<int> &dist)
{
    queue<int> q; q.push(u);
    vector<bool> vis(vn, false); vis[u] = true;
    dist[u] = 0;
    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(auto v : graph[u])
        {
            if(vis[v]) continue;
            dist[v] = dist[u]+1;
            vis[v] = true;
            q.push(v);
        }
    }
}

void process()
{
    bfs(a, dist_a);
    bfs(b, dist_b);
    bfs(c, dist_c);
    ll ans = 1ll<<60;
    /*
    cerr << "dist_a : ";
    for(auto x : dist_a) cerr << x << " ";
    cerr << endl;
    cerr << "dist_b : ";
    for(auto x : dist_b) cerr << x << " ";
    cerr << endl;
    cerr << "dist_c : ";
    for(auto x : dist_c) cerr << x << " ";
    cerr << endl;
    */
    for(int y = 0; y < vn; y++)
    {
        // a -> y -> b -> y -> c
        ll d_ay = dist_a[y];
        ll d_by = dist_b[y];
        ll d_cy = dist_c[y];
        if(d_ay + d_by + d_cy > en) continue;
        ll sum = w[d_by] + w[d_ay + d_by + d_cy];
//        cerr << var(y) << var(sum) << var(d_ay+d_by+d_cy) << endl;
        ans = min(ans, sum);
    }
    cout << ans << endl;
}

