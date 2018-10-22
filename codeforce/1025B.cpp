//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a*b/gcd(a, b); }

ll smallPrime(ll x)
{
    for(ll i = 2; i*i <= x; i++)
    {
        if(x%i == 0) return i;
    }
    return x;
}

void process()
{
    ll n, a, b; cin >> n >> a >> b;
    ll tmp = lcm(a, b), ans;
    for(int i = 1; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        tmp = gcd(lcm(a, b), tmp);
    }
    ans = gcd(tmp, a);
    if(ans > 1) { cout << smallPrime(ans) << endl; return; }
    ans = gcd(tmp, b);
    if(ans > 1) { cout << smallPrime(ans) << endl; return; }
    cout << -1 << endl;
}

