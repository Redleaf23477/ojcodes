//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

ll n, d, e;

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
    cin >> n >> d >> e;
    e *= 5;
}

void process()
{
    ll ans = n;
    for(int i = 0; i <= n / d; i++)
    {
        ll left = n - i * d;
        ans = min(ans, left - left / e * e);
    }
    cout << ans << endl;
}

