// detecting negative cycle
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<double, int> Edge;
#define w first
#define idx second

const int N = 802;
const double INF = 1e9;
const double eps = 1e-6;

int vn, en;
vector<Edge> G[N];
int vis[N];
double dist[N];

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
    cin >> vn >> en;
    for(int i = 0; i < en; i++)
    {
        int from, to; double w; cin >> from >> to >> w;
        G[from].emplace_back(-log(w), to);
    }
    for(int i = 1; i <= vn; i++) vis[i] = 0, dist[i] = INF;
}

bool negativeCycle(int s)  // using spfa
{
    queue<int> q;
    vector<bool> inq(vn+1, false);
    q.push(s); inq[s] = true;
    dist[s] = 0;
    while(!q.empty())
    {
        int f = q.front(); q.pop();
        if(++vis[f] == vn) return true;
        inq[f] = false;
        for(auto c:G[f])
        {
            double newDist = dist[f]+c.w;
            if(newDist+eps < dist[c.idx])
            {
                dist[c.idx] = newDist;
                if(!inq[c.idx]) { inq[c.idx] = true; q.push(c.idx); }
            }
        }
    }
    return false;
}

void process()
{
    bool neg = negativeCycle(1);
    if(neg) cout << "inadmissible" << endl;
    else cout << "admissible" << endl;
}

