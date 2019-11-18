//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll INF = 1ll<<60;

ll t;

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
    cin >> t;
}

ll pwer(ll a, ll p)
{
    ll ans = 1;
    for(int i = 0; i < p; i++) ans *= a;
    return ans;
}

ll run(ll mxpw)
{
    ll initSec = 2*(mxpw);
    ll initRun = 2*pwer(3, mxpw)-1-1;
    if(t < initRun) return INF;
    else if(initRun == t) return initSec;
    else 
    {
        ll ans = initSec;
        ll rest = t - initRun;
        ll pw = pwer(3, mxpw);
        while(rest > 0)
        {
            ans += rest/pw, rest %= pw;
            pw /= 3;
        }
        return ans;
    }
}

void process()
{
    ll ans = t;
    for(ll pw = 1; pw < 33; pw++)
    {
        ll res = run(pw);
        ans = min(ans, res);
    }
    cout << ans << endl;
}

