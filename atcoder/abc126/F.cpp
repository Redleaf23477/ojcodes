//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll n, k;

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
    cin >> n >> k;
}

void process()
{
    if(k == 0)
    {
        for(ll i = 0; i < (1<<n); i++) cout << i << " " << i << " ";
        cout << endl;
    }
    else if(n == 1 && k == 1) cout << -1 << endl;
    else if(k < (1<<n))
    {
        for(ll i = 0; i < (1<<n); i++) if(i != k) cout << i << " ";
        cout << k << " ";
        for(ll i = (1<<n)-1; i >= 0; i--) if(i != k) cout << i << " ";
        cout << k << endl;
    }
    else cout << -1 << endl;
}

