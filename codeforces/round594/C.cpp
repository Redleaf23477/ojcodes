//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll MOD = 1e9+7;
ll n, m;

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
    cin >> n >> m;
}

ll f(ll x)
{
    ll a = 1, b = 2, c;
    if(x == 1) return 1;
    if(x == 2) return 2;
    for(int i = 3; i <= x; i++)
    {
        c = (a + b)%MOD;
        a = b, b = c;
    }
    return c;
}

void process()
{
    cout << 2*(f(n)+f(m)-1)%MOD << endl;
}

