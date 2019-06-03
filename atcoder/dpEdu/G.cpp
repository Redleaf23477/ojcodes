//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;

int vn, en;
int indeg[N];
vector<int> graph[N];
ll dist[N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> vn >> en;
    for(int i = 0; i < en; i++)
    {
        int f, t; cin >> f >> t;
        graph[f].push_back(t);
        indeg[t]++;
    }
}

void process()
{
    queue<int> q;
    for(int i = 1; i <= vn; i++) if(indeg[i] == 0) q.push(i);
    while(!q.empty())
    {
        int f = q.front(); q.pop();
        for(auto t:graph[f]) 
        {
            dist[t] = max(dist[t], dist[f]+1);
            if(--indeg[t] == 0) q.push(t);
        }
    }
    ll mx = 0;
    for(auto d:dist) mx = max(mx, d);
    cout << mx << endl;
}

