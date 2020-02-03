//
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
using namespace std;
typedef long long int ll;

ll n, mod;

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
    cin >> n >> mod;
}

void process()
{
    ll sum = 0;
    vector<ll> fac(n+1);
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= n; i++) fac[i] = fac[i-1]*i%mod;
    for(ll len = 1; len <= n; len++)
    {
        ll pos = (n-len+1) * fac[len] % mod;
        ll slot = n-len+1;
        ll restPos = fac[n - len] % mod;
//        cout << var(len) << var(pos) << var(slot) << var(restPos) << endl;
        sum = (sum + pos*slot%mod*restPos%mod)%mod;
    }
    cout << sum << endl;
}

/*
 * n = 2:
 * 12 -> 1_, _2, 12
 * 21 -> 2_, _1, 21
 */
