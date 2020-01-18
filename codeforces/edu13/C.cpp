//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, a, b, p, q;

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
    cin >> n >> a >> b >> p >> q;
}

void process()
{
    ll ans = n/a*p + n/b*q;
    if(p > q) ans -= n/(a*b/__gcd(a,b))*q;
    else ans -= n/(a*b/__gcd(a,b))*p;
    cout << ans << endl;
}

