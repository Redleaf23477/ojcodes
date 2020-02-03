// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll a, m;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
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
    cin >> a >> m;
}

void get_pf(ll x, vector<ll> &pf)
{
    for(ll i = 2; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            pf.push_back(i);
            while(x%i == 0) x /= i;
        }
    }
    if(x != 1) pf.push_back(x);
}

ll run(ll lim, ll g, vector<ll> &pf)
{
    ll ans = 0;
    ll pfsz = pf.size();
    for(ll bs = 0; bs < (1ll<<pfsz); bs++)
    {
        ll ones = 0, mul = g;
        for(ll i = 0; i < pfsz; i++)
        {
            if((bs>>i)&1)
            {
                ones++;
                mul *= pf[i];
            }
        }
        if(ones%2 == 1)
            ans -= lim / mul;
        else 
            ans += lim / mul;
    }
    return ans;
}

void process()
{
    ll g = __gcd(a, m);
    vector<ll> pf; // prime factors
    get_pf(m/g, pf);
    
    /*
    cout << "pf : ";
    for(auto p : pf) cout << p << " ";
    cout << endl;
    */

    ll ans = run(a+m-1, g, pf);

    ans -= run(a-1, g, pf);

    cout << ans << endl;
}

