//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

template<typename T>
struct DINIC{
    static const int MAXN=3005;
    static const T INF=INT_MAX;
    int n, level[MAXN], cur[MAXN];
    struct edge{
        int v,pre;
        T r;
        edge(int v,int pre,T cap):v(v),pre(pre),r(cap){}
    };
    int g[MAXN];
    vector<edge> e;
    void init(int _n){
        memset(g,-1,sizeof(int)*((n=_n)+1));
        e.clear();
    }
    void add_edge(int u,int v,T cap,bool directed=false){
        e.push_back(edge(v,g[u],cap));
        g[u]=e.size()-1;
        e.push_back(edge(u,g[v],directed?0:cap));
        g[v]=e.size()-1;
    }
    int bfs(int s,int t){
        memset(level,0,sizeof(int)*(n+1));
        memcpy(cur,g,sizeof(int)*(n+1));
        queue<int> q;
        q.push(s);
        level[s]=1;
        while(q.size()){
            int u=q.front();q.pop();
            for(int i=g[u];~i;i=e[i].pre){
                if(!level[e[i].v]&&e[i].r){
                    level[e[i].v]=level[u]+1;
                    q.push(e[i].v);
                    if(e[i].v==t)return 1;
                }
            }
        }
        return 0;
    }
    T dfs(int u,int t,T cur_flow=INF){
        if(u==t)return cur_flow;
        T df;
        for(int &i=cur[u];~i;i=e[i].pre){
            if(level[e[i].v]==level[u]+1&&e[i].r){
                if(df=dfs(e[i].v,t,min(cur_flow,e[i].r))){
                    e[i].r-=df;
                    e[i^1].r+=df;
                    return df;
                }
            }
        }
        return level[u]=0;
    }
    T dinic(int s,int t){
        T ans=0, mf=0;
        while(bfs(s,t))while(mf=dfs(s,t))ans+=mf;
        return ans;
    }
};

DINIC<int> flow;

int S, T, n, m, vn, en;

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
    cin >> n >> m >> en;
    S = 0, T = n+m+1, vn = T+1;
    flow.init(vn);
    for(int v = 1; v <= n; v++)
        flow.add_edge(S, v, 1, true);
    for(int u = n+1; u <= n+m; u++)
        flow.add_edge(u, T, 1, true);
    for(int i = 0; i < en; i++)
    {
        int from, to; cin >> from >> to;
        flow.add_edge(from, n+to, 1, true);
    }
}

void process()
{
    int oriFlow = flow.dinic(S, T);
    int newFlow = 0;
    auto backup = flow.e;
    for(int u = 1; u <= n; u++)
    {
        flow.e = backup;
        flow.e[(u-1)*2].r += 2;
        newFlow = max(newFlow, flow.dinic(S, T));
    }
    cout << oriFlow + newFlow << endl;
}

