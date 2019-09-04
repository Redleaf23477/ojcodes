//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
using Pt = pair<ll,ll>;
#define r first
#define c second

const int N = 3030;
const int M = 200005;
const ll MOD = 1e9+7;

ll h, w, n;
Pt arr[N];
ll dp[N]; // dp[i] - # of valid path to ith invalid pt
ll fac[M], fac_inv[M];

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

ll sub(ll lhs, ll rhs) { return (lhs - rhs + MOD)%MOD; }
ll mul(ll lhs, ll rhs) { return (lhs * rhs % MOD); }
ll fastPw(ll a, ll p)
{
    ll r = 1;
    while(p)
    {
        if(p&1) r = mul(r, a);
        a = mul(a, a);
        p >>= 1;
    }
    return r;
}

ll modInv(ll x) { return fastPw(x, MOD-2); }

ll pathTo(Pt from, Pt to)
{
    ll dr = to.r - from.r;
    ll dc = to.c - from.c;
    return mul(mul(fac[dr+dc],fac_inv[dr]),fac_inv[dc]);
}

void init()
{
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i].r >> arr[i].c;
    sort(arr, arr+n);
    fac[0] = fac[1] = 1;
    fac_inv[0] = fac_inv[1] = modInv(1);
    for(int i = 2; i < M; i++)
    {
        fac[i] = mul(fac[i-1], i);
        fac_inv[i] = modInv(fac[i]);
    }
}

void process()
{
    for(int i = 0; i < n; i++)
    {
        dp[i] = pathTo(make_pair(1,1), arr[i]);
        for(int j = 0; j < i; j++)
        {
            if(arr[j].r <= arr[i].r && arr[j].c <= arr[i].c)
                dp[i] = sub(dp[i], mul(dp[j], pathTo(arr[j], arr[i])));
        }
    }
    ll ans = pathTo(make_pair(1, 1), make_pair(h, w));
    for(int i = 0; i < n; i++)
    {
        ans = sub(ans, mul(dp[i], pathTo(arr[i], make_pair(h, w))));
    }
    cout << ans << endl;
}

