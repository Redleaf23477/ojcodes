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
    init();
    cout.flush();
    return 0;
}

void init()
{
    int q; cin >> q;
    while(q--)
    {
        ll n, a, b; cin >> n >> a >> b;
        if(b >= a*2)
        {
            cout << n*a << endl;
        }
        else
        {
            cout << n/2*b + n%2*a << endl;
        }
    }
}

void process()
{
}

