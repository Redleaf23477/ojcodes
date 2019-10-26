//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, r;
set<ll> arr;

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
    cin >> n >> r;
    arr.clear();
    for(int i = 0; i < n; i++) 
    {
        ll x; cin >> x;
        arr.insert(x);
    }
}

void process()
{
    ll ans = 0;
    ll sum = 0;
    for(auto it = arr.rbegin(); it != arr.rend(); it++)
    {
        if(*it - sum <= 0) break;
        ans++, sum += r;
    }
    cout << ans << endl;
}

