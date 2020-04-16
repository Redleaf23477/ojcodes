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
vector<bool> inCyc;
//vector<vector<int>> cyc;
vector<int> cyc;
vector<int> cycLen;
set<int> acc[N];
vector<int> indeg;
vector<bool> vis;
 
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
    inCyc.resize(n); fill(inCyc.begin(), inCyc.end(), 0);
    indeg.resize(n); fill(indeg.begin(), indeg.end(), 0);
    vis.resize(n); fill(vis.begin(), vis.end(), 0);
    cyc.clear(), cycLen.clear();
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
    vis[u] = true;
    int v = to[u];
    if(inPath[v])
    {
        int cidx = -1;
        int len = 0;
//        vector<int> c;
        for(int i = path.size()-1; i >= 0; i--)
        {
            len++;
//            c.push_back(path[i]);
            inCyc[path[i]] = true;
            if(path[i] == v) 
            {
                cidx = i; break;
            }
        }
        cyc.push_back(v);
        cycLen.push_back(len);
//        cyc.push_back(c);
        for(int i = 0; i < cidx; i++)
        {
            if(color[path[i]] == '1') continue;
            int dist = cidx - i;
            acc[path[cidx]].insert(dist);
        }
    }
    else if(inCyc[v])
    {
        for(int i = 0; i < (int) path.size(); i++)
        {
            if(color[path[i]] == '1') continue;
            int dist = path.size()-i;
            acc[v].insert(dist);
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
        if(vis[i] == false)
            dfs(i);
    }
    for(int a = 0; a < (int)cyc.size(); a++)
    {
        auto &c = cyc[a];
        int len = cycLen[a];
        set<int> s;
        for(int i = 0, ci = c; i < len; i++, ci = to[ci])
        {
            int x = ci;
            ans1++;
            if(color[x] == '0') acc[x].insert(0);
            for(auto p : acc[x]) 
            {
                int key = (len-i+p) % len;
                s.insert(key);
            }
        }
        ans2 += s.size();
    }
    
    /*
    cerr << "check cycles" << endl;
    for(auto c : cyc)
    {
        cerr << "found cycle : ";
        for(auto x : c) 
        {
            cerr << x << " ";
        }
        cerr << endl;
    }
    cerr << "check black" << endl;
    for(auto c : cyc)
    {
        for(auto x : c)
        {
            cerr << var(x) << " => ";
            for(auto p : acc[x]) cerr << "(d=" << p.first << ", #=" << p.second << ")";
            cerr << endl;
        }
    }
    */
    
    cout << ans1 << " " << ans2 << endl;
}
 
