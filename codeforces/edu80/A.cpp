//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, d;

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
    cin >> n >> d;
}

ll ceil(ll x, ll y)
{
    return x / y + (x%y > 0);
}

void process()
{
    for(ll x = 0; x <= n; x++)
    {
        if(x + ceil(d, x+1) <= n) 
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
