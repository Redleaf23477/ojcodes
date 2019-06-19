//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(a != d) cout << 0 << endl;
    else
    {
        if(c == 0) cout << 1 << endl;
        else if(a > 0) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

