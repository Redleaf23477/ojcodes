//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
const ll INF = (1ll << 60);

struct Fraction
{
    ll up, down;
    Fraction(ll up, ll down):up(up), down(down)
    {
        normalize();
    }
    void normalize()
    {
        ll g = __gcd(up, down);
        if(g == 0) return;
        up /= g, down /= g;
    }
    Fraction operator * (const Fraction that) const 
    {
        Fraction ret(up*that.up, down*that.down);
        ret.normalize();
        return ret;
    }
    bool operator < (const Fraction &that) const
    {
        ll me = up*that.down, you = down*that.up;
        return me < you;
    }
    bool operator > (const Fraction &that) const
    {
        ll me = up*that.down, you = down*that.up;
        return me > you;
    }
};


typedef pair<Fraction, int> Edge;
#define w first
#define idx second 

struct Cmp
{
    bool operator() (const Edge &lhs, const Edge &rhs) 
    {
        return (lhs.w < rhs.w);
    }
};

const int N = 1010;
int vn, S, T;
vector<Edge> G[N];

void init();
void process();

int main()
{
//    ios::sync_with_stdio(false); cin.tie(0);
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
    int en;
    cin >> vn >> S >> T >> en;
    for(int i = 0; i < vn; i++) G[i].clear();
    for(int i = 0; i < en; i++)
    {
        int u, v, up, down; cin >> u >> v >> up >> down;
        G[u].emplace_back(Fraction(up, down), v);
    }
}

Fraction dijk()
{
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    vector<bool> vis(vn, 0);
    vector<Fraction> dist(vn, Fraction(0, 1));
    dist[S] = Fraction(1, 1);
    pq.emplace(dist[S], S); 
    while(!pq.empty())
    {
        Edge tp = pq.top(); pq.pop();
        vis[tp.idx] = true;
        if(vis[T]) break;
        for(auto c:G[tp.idx])
        {
            Fraction w = c.w * tp.w;
            if(!vis[c.idx] && w > dist[c.idx])
            {
                dist[c.idx] = w;
                pq.emplace(dist[c.idx], c.idx);
            }
        }
    }
    return dist[T];
}

void process()
{
    Fraction res = dijk();
    if(res.up == 0) cout << -1 << endl;
    else cout << res.up << " " << res.down << endl;
}

