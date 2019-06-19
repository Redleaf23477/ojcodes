//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef unsigned long long ll;

ll n, b;
map<ll, ll> fac;
map<ll, ll> fcnt;

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

void facize(ll x)
{
    ll y = x;
    for(ll i = 2; i*i <= x; i++)
    {
        if(y%i == 0)
        {
            fac[i] = 1;
            fcnt[i] = 0;
            while(y%i == 0) fac[i]*=i, fcnt[i]++, y/=i;
        }
    }
    if(y != 1) fcnt[y] = 1, fac[y] = y;

    ll chk = 1;
    for(auto p:fac) chk *= p.second;
    assert(chk == x);
}

void init()
{
    cin >> n >> b;
    facize(b);
    /*
    for(auto p:fac)
    {
        cout << p.first << " " << p.second << " " << fcnt[p.first] << endl;
    }
    */
}

void process()
{
    vector<ll> tmp;
    for(auto p:fac)
    {
        ll cnt = 0;
        for(ll x = p.first; x <= n; x *= p.first) 
        {
            cnt += n/x;
            if(x > n/p.first) break;
        }
        cnt /= fcnt[p.first];
        tmp.push_back(cnt);
        cerr << ".." << p.first << " : " << cnt << endl;
    }
    ll mn = tmp[0];
    for(auto x:tmp) mn = min(x, mn);
    cout << mn << endl;
}

