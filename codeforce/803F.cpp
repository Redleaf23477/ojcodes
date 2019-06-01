//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const ll M = 100005;
const ll MOD = 1e9+7;

ll n;

ll sp[M], mobius[M];
ll cnt[M];
ll pw2[M];

void sieve()
{
    for(ll i = 0; i < M; i++) sp[i] = i;
    for(ll i = 2; i*i < M; i++) if(sp[i] == i) 
    {
        for(ll j = i*i; j < M; j += i) 
            if(sp[j] == j) sp[j] = i;
    }
}

void makeMobius()
{
    for(ll i = 0; i < M; i++) mobius[i] = 1;
    mobius[0] = 0;
    for(ll i = 2; i < M; i++) if(sp[i] == i)
    {
        for(ll j = i; j < M; j += i) mobius[j] = -mobius[j];
        for(ll j = i*i; j < M; j += i*i) mobius[j] = 0;
    }
}

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
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        ll x; cin >> x;
        cnt[x]++;
    }

    sieve();
    makeMobius();


    pw2[0] = 1;
    for(int i = 1; i < M; i++) pw2[i] = pw2[i-1]*2%MOD;
}

void process()
{
    ll ans = 0;
    for(ll i = 1; i < M; i++)
    {
        if(mobius[i] == 0) continue;
        ll c = 0;
        for(int j = i; j < M; j+=i) c += cnt[j];
        ans = (ans + MOD + mobius[i]*(pw2[c]-1)%MOD)%MOD;
    }
    cout << (ans+MOD)%MOD << endl;
}

