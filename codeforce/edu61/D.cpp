//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define power first
#define usage second

struct Cmp
{
    bool operator () (const P &lhs, const P &rhs)
    {
        return lhs.power/lhs.usage > rhs.power/rhs.usage;
    }
};

typedef priority_queue<P, vector<P>, Cmp> PQ;

const int N = 200005;

ll n, totTime;
PQ init_pq;

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
    cin >> n >> totTime;
    ll initPw[N], usage[N];
    for(int i = 0; i < n; i++) cin >> initPw[i];
    for(int i = 0; i < n; i++) cin >> usage[i];
    for(int i = 0; i < n; i++)
    {
        init_pq.emplace(initPw[i], usage[i]);
    }
}

bool ok(ll charge)
{
    PQ pq = init_pq;
    for(ll t = 1; t < totTime; t++)
    {
        P f = pq.top(); pq.pop();
        f.power += charge;
        pq.push(f);
        f = pq.top();
        if(f.usage*t > f.power) return false;
    }
    return true;
}

void bs(ll l, ll h)
{
    ll low = l, high = h, mid, ans = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}

void process()
{
    // exp
    ll MAX = 4000000000000ll;
    ll pw = 1;
    while(!ok(pw) && pw < MAX) pw *= 2;
    if(pw >= MAX) cout << -1 << endl;
    else bs(pw/2, pw);
}


