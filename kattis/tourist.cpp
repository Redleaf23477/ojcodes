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

///////////////////////////////////

template<typename TP>
struct MCMF{
    static const int MAXN=440;
    static const TP INF=999999999;
    struct edge{
        int v,pre;
        TP r,cost;
        edge(int v,int pre,TP r,TP cost):v(v),pre(pre),r(r),cost(cost){}
    };
    int n,S,T;
    TP dis[MAXN],PIS,ans;
    bool vis[MAXN];
    vector<edge> e;
    int g[MAXN];
    void init(int _n){
        memset(g,-1,sizeof(int)*((n=_n)+1));
        e.clear();
    }
    void add_edge(int u,int v,TP r,TP cost,bool directed=false){
        e.push_back(edge(v,g[u],r,cost));
        g[u]=e.size()-1;
        e.push_back(
                edge(u,g[v],directed?0:r,-cost));
        g[v]=e.size()-1;
    }
    TP augment(int u,TP CF){
        if(u==T||!CF)return ans+=PIS*CF,CF;
        vis[u]=1;
        TP r=CF,d;
        for(int i=g[u];~i;i=e[i].pre){
            if(e[i].r&&!e[i].cost&&!vis[e[i].v]){
                d=augment(e[i].v,min(r,e[i].r));
                e[i].r-=d;
                e[i^1].r+=d;
                if(!(r-=d))break;
            }
        }
        return CF-r;
    }
    bool modlabel(){
        for(int u=0;u<=n;++u)dis[u]=INF;
        static deque<int>q;
        dis[T]=0,q.push_back(T);
        while(q.size()){
            int u=q.front();q.pop_front();
            TP dt;
            for(int i=g[u];~i;i=e[i].pre){
                if(e[i^1].r&&(dt=dis[u]-e[i].cost)<dis[e[i].v]){
                    if((dis[e[i].v]=dt)<=dis[q.size()?q.front():S]){
                        q.push_front(e[i].v);
                    }else q.push_back(e[i].v);
                }
            }
        }
        for(int u=0;u<=n;++u)
            for(int i=g[u];~i;i=e[i].pre)
                e[i].cost+=dis[e[i].v]-dis[u];
        return PIS+=dis[S], dis[S]<INF;
    }
    TP mincost(int s,int t){
        S=s,T=t;
        PIS=ans=0;
        while(modlabel()){
            do memset(vis,0,sizeof(bool)*(n+1));
            while(augment(S,INF));
        }return ans;
    }
};

///////////////////////////////////


const int N = 110;

int R, C;
char arr[N][N];
MCMF<double> mcmf;

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
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> arr[r][c];
    int n = R*C;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] == '.')
            {
            }
            else if(arr[r][c] == '#')
            {
            }
            else 
            {
            }
        }
        
}

void process()
{
}

