//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll MOD = 1e9+7;

ll a, b, n, x;

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
    cin >> a >> b >> n >> x;
}

ll fpw(ll a, ll p)
{
    if(p == 0) return 1;
    else if(p%2 == 0) return fpw(a*a%MOD, p/2);
    else return a * fpw(a*a%MOD, p/2) %MOD;
}

void process()
{
    ll ax = fpw(a, n) * x % MOD;
    ll baaaa = b * (1 * (fpw(a, n)+MOD-1) % MOD * fpw(a-1, MOD-2) % MOD) % MOD;
    if(a == 1) baaaa = b * (n%MOD) % MOD;
    ll ans = (ax + baaaa) % MOD;
    cout << ans << endl;
}

