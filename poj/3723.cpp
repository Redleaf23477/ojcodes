//
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
#define w first
#define idx second

const int N = 20004;

int vn;
vector<P> graph[N];
vector<bool> vis;

void init();
void process();

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    int boy, girl, rel; scanf("%d %d %d", &boy, &girl, &rel);
    vn = boy+girl;
    vis.resize(vn); fill(vis.begin(), vis.end(), false);
    for(int i = 0; i < vn; i++) graph[i].clear();
    for(int i = 0; i < rel; i++)
    {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        b = boy+b;
        graph[a].push_back(P(c, b));
        graph[b].push_back(P(c, a));
    }
}

ll prim(int s)
{
    ll mst = 0;
    priority_queue<P, vector<P>, less<P> > pq;
    pq.push(P(0, s));
    while(!pq.empty())
    {
        P tp = pq.top(); pq.pop();
        if(vis[tp.idx]) continue;
        vis[tp.idx] = true;
        mst += tp.w;
        for(vector<P>::iterator it = graph[tp.idx].begin(); it != graph[tp.idx].end(); it++)
        {
            if(!vis[it->idx]) pq.push(*it);
        }
    }
    return mst;
}

void process()
{
    ll tot = 0;
    for(int i = 0; i < vn; i++)
    {
        if(!vis[i]) tot += prim(i);
    }
    printf("%lld\n", 10000*vn-tot);
}

