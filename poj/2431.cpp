//poj 2431
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;
#define x first
#define w second

const int N = 100005;
int n;
P stop[N];

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
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %lld", &stop[i].x, &stop[i].w);
    sort(stop, stop+n);
}

void process()
{
    ll dist, tank; scanf("%lld %lld", &dist, &tank); dist -= tank;
    priority_queue<ll, vector<ll>, less<ll> > pq;
    int idx = n-1, cnt = 0;
    while(idx >= 0 && stop[idx].x >= dist) pq.push(stop[idx--].w);
    while(dist > 0 && !pq.empty())
    {
        dist -= pq.top(); pq.pop(); cnt++;
        while(idx >= 0 && stop[idx].x >= dist) pq.push(stop[idx--].w);
    }
    if(dist <= 0) printf("%d\n", cnt);
    else printf("-1\n");
}

