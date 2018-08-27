// poj 3255 roadblocks
// dijkstra
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair<ll, int> Edge;
#define w first
#define idx second

const int N = 5050;
const ll INF = (1ll<<60);

int vn, en;
vector<Edge> graph[N];
ll dist1[N], dist2[N];

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    scanf("%d %d", &vn, &en);
    for(int i = 0; i < en; i++)
    {
        int f, t, w;  scanf("%d %d %d", &f, &t, &w);
        graph[f].push_back(Edge(w, t));
        graph[t].push_back(Edge(w, f));
    }
}

void dijkstra(int s)
{
    for(int i = 0; i <= vn; i++) dist1[i] = INF;
    dist1[s] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    pq.push(Edge(0, s));
    while(!pq.empty())
    {
        Edge f = pq.top(); pq.pop();
        if(f.w > dist1[f.idx]) continue;
        for(vector<Edge>::iterator it = graph[f.idx].begin(); it != graph[f.idx].end(); it++)
        {
            if(dist1[it->idx] > dist1[f.idx]+it->w)
            {
                dist1[it->idx] = dist1[f.idx]+it->w;
                pq.push(Edge(dist1[it->idx], it->idx));
            }
        }
    }
}

void bellman2(int s)
{
    for(int i = 0; i <= vn; i++) dist2[i] = INF;
    for(vector<Edge>::iterator it = graph[s].begin(); it != graph[s].end(); it++)
    {
        dist2[s] = min(dist2[s], dist1[it->idx]+it->w);
        dist2[s] = min(dist2[s], 2*dist1[it->idx]);
    }
    bool update = true;
    while(update)
    {
        update = false;
        for(int i = 1; i <= vn; i++)
        {
            for(vector<Edge>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
            {
                ll d2 = INF;
                if(dist1[i]+it->w != dist1[it->idx]) d2 = min(dist1[i]+it->w, d2);
                d2 = min(dist2[i]+it->w, d2);
                if(d2 < dist2[it->idx])
                {
                    update = true;
                    dist2[it->idx] = d2;
                }
            }
        }
    }
}


void process()
{
    dijkstra(1);
    bellman2(1);
//    for(int i = 1; i <= vn; i++) printf("%lld%c", dist1[i], " \n"[i==vn]);
//    for(int i = 1; i <= vn; i++) printf("%lld%c", dist2[i], " \n"[i==vn]);
    printf("%lld\n", dist2[vn]);
}

