#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX_N=2e3+3;

struct P
{
    ll leftDay, startWork, idx;
    P (ll a, ll b, ll c):leftDay(a), startWork(b), idx(c){}
};

bool operator < (const P &lhs, const P &rhs)
{
    return lhs.leftDay < rhs.leftDay;
}


ll m,n,w,h;
priority_queue<P, vector<P>, less<P>> pq;
ll D[MAX_N];
ll tmp[MAX_N];
vector<ll> ans[MAX_N];

void init()
{
    cin >> m >> n >> w >> h;
    for(int i = 0; i < m; i++)
    {
        ll x; cin >> x;
        pq.emplace(x, 0, i);
    }
    for(int i = 0; i < n; i++) cin >> D[i];
}

bool good()
{
    queue<P> rest;
    ll sum = 0;
    for(int d = 0; d < n; d++)
    {
        while(!rest.empty() && d == rest.front().startWork)
        {
            P f = rest.front(); rest.pop();
            pq.push(f);
        }
        sum += tmp[d];
        if(sum > D[d]) return false;
        else if(sum == D[d]) continue;
        else
        {
            if(pq.size() < D[d]-sum) return false;
            ll need = D[d]-sum;
            while(need--)
            {
                P f = pq.top(); pq.pop();
                sum++;
                tmp[d+w]--;
                if(d+w > n) return false;
                if(f.leftDay-w > 0) rest.emplace(f.leftDay-w, d+w+h, f.idx);
                ans[f.idx].push_back(d+1);
            }
        }
    }
    if(!pq.empty()) return false;
    if(!rest.empty()) return false;
    return true;
}

void process()
{
    if(good())
    {
        cout << 1 << endl;
        for(int i = 0; i < m; i++)
        {
            for(auto x:ans[i]) cout << x << " ";
            cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}
