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
 
const int N = 1000006;
 
int R, C, n;
vector<int> to;
vector<char> color;
vector<int> inCyc;
vector<int> cyc;
vector<int> cycLen;
vector<int> cycIdx;
set<int> acc[N];
vector<int> indeg;
vector<int> vis;
vector<int> d2cyc;
 
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
    cin >> R >> C;
    n = R * C;
    to.resize(n);
    color.resize(n);
    inCyc.resize(n); fill(inCyc.begin(), inCyc.end(), -1);
    indeg.resize(n); fill(indeg.begin(), indeg.end(), 0);
    cycIdx.resize(n); fill(cycIdx.begin(), cycIdx.end(), 0);
    vis.resize(n); fill(vis.begin(), vis.end(), -1);
    d2cyc.resize(n); fill(d2cyc.begin(), d2cyc.end(), 0);
    cyc.clear();
    cycLen.resize(n); fill(cycLen.begin(), cycLen.end(), 0);
    for(int i = 0; i < n; i++) acc[i].clear();
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            char ch; cin >> ch;
            color[r*C+c] = ch;
        }
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            int rr = r, cc = c;
            char ch; cin >> ch;
            if(ch == 'U') rr--;
            else if(ch == 'D') rr++;
            else if(ch == 'L') cc--;
            else cc++;
            to[r*C+c] = rr*C+cc;
            indeg[rr*C+cc]++;
        }
}
 
void dfs(int u)
{
    static vector<int> path; 
    static vector<bool> inPath(n, false);
    path.push_back(u);
    inPath[u] = true;
    int v = to[u];
    if(inPath[v])
    {
        int cidx = -1;
        int len = 0;
        for(int i = path.size()-1; i >= 0; i--)
        {
            len++;
            inCyc[path[i]] = v;
            vis[path[i]] = v;
            if(path[i] == v) 
            {
                cycIdx[v] = 0;
                if(color[v] == '0') acc[v].insert(0);
                cidx = i; break;
            }
            cycIdx[path[i]] = len;
            if(color[path[i]] == '0') acc[v].insert(len);
        }
        cyc.push_back(v);
        cycLen[v] = len;
        for(int i = 0; i < cidx; i++)
        {
            vis[path[i]] = v;
            int dist = (cidx - i) % len;
            d2cyc[path[i]] = dist;
            if(color[path[i]] == '1') continue;
            acc[v].insert(dist);
        }
    }
    else if(inCyc[v] != -1)
    {
        for(int i = 0; i < (int) path.size(); i++)
        {
            vis[path[i]] = inCyc[v];
            int dist = (path.size() - i + cycIdx[v]) % cycLen[inCyc[v]];
            d2cyc[path[i]] = dist;
            if(color[path[i]] == '1') continue;
            acc[inCyc[v]].insert(dist);
        }
    }
    else if(vis[v] != -1)
    {
        for(int i = 0; i < (int) path.size(); i++)
        {
            vis[path[i]] = vis[v];
            int dist = (path.size() - i + d2cyc[v]) % cycLen[inCyc[vis[v]]];
            d2cyc[path[i]] = dist;
            if(color[path[i]] == '1') continue;
            acc[vis[v]].insert(dist);
        }
    }
    else dfs(v);
    path.pop_back();
    inPath[u] = false;
}
 
void process()
{
    ll ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
            dfs(i);
    }
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == -1)
            dfs(i);
    }
    for(auto c : cyc)
    {
        ans1 += cycLen[c];
        ans2 += acc[c].size();
    }
    cout << ans1 << " " << ans2 << endl;
}
 
