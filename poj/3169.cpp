// poj 3169
// 差分約束 + shortest path
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long int ll;
typedef pair<ll, int> Edge;
#define w first
#define idx second

const int N = 1010;
const ll INF = (1ll<<60);

int vn, pen, nen;
vector<Edge> graph[N];

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
    scanf("%d %d %d", &vn, &pen, &nen);
    for(int i = 0; i < vn-1; i++)
    {
        graph[i+1].push_back(Edge(0, i));
    }
    for(int i = 0; i < pen; i++)
    {
        int f, t, w; scanf("%d %d %d", &f, &t, &w);
        f--, t--;
        graph[f].push_back(Edge(w, t));
    }
    for(int i = 0; i < nen; i++)
    {
        int f, t, w; scanf("%d %d %d", &t, &f, &w);
        f--, t--, w = -w;
        graph[f].push_back(Edge(w, t));
    }
}

// using spfa
ll shortest_path(int s)
{
    vector<ll> dist(vn, INF); dist[s] = 0;
    vector<bool> inque(vn, false);
    vector<int> cnt(vn, 0);
    queue<int> q; q.push(s); inque[s] = true;
    while(!q.empty())
    {
        int f = q.front(); q.pop();
        inque[f] = false;
        if(++cnt[f] == vn) return -1;
        for(vector<Edge>::iterator it = graph[f].begin(); it != graph[f].end(); it++)
        {
            if(dist[f]+it->w < dist[it->idx])
            {
                dist[it->idx] = dist[f]+it->w;
                if(!inque[it->idx])
                {
                    inque[it->idx] = true;
                    q.push(it->idx);
                }
            }
        }
    }
//    for(auto x:dist) cout << x << " "; cout << endl;
    return dist[vn-1] == INF? -2:dist[vn-1];
}

void process()
{
    printf("%lld\n", shortest_path(0));
}

