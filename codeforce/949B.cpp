//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll n, q;

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

void init()
{
    cin >> n >> q;
}

void process()
{
    while(q--)
    {
        ll x; cin >> x;
        if(x%2 == 1) 
        {
            cout << 1 + x/2 << endl; continue;
        }
        ll rightNum = n-x + (x-1)/2;
        while(true)
        {
//            cout << ".." << x << endl;
            ll newx = x + rightNum + 1;
            rightNum = newx/2 - x/2 -1;
            x = newx;
            if(newx%2 == 1) break;
        }
        cout << (x-1)/2+1 << endl;
    }
}

