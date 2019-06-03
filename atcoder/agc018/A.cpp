//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> arr;

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
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    ll g = arr[0];
    for(auto x:arr) g = __gcd(g, x);
    for(auto x:arr)
    {
        if(x-k >= 0 && (x-k)%g == 0)
        {
            cout << "POSSIBLE" << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

