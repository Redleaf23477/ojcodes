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
    if(k*k-k < n) 
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(ll s = 3; s < k+k; s++)
    {
        for(ll p = max(1ll, s-k), c = 1; c < s && p <= k; c++, p++)
        {
            if(p == s-p) continue;
            cout << p << " " << s-p << endl;
            if(--n == 0) return;
        }
    }
}
