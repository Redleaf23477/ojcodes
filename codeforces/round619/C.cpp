// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n, m;

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
    cin >> n >> m;
}

void process()
{
    ll zero = n - m;
    ll len = zero / (m+1);
    ll rem = zero % (m+1);
    pair<ll,ll> g1(len+1, rem), g2(len, m+1-rem);
    ll ans = n*(n+1)/2;
    ans -= g1.second * (g1.first*(g1.first+1)/2);
    ans -= g2.second * (g2.first*(g2.first+1)/2);
    cout << ans << endl;
}
