//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

ll n, k;
vector<ll> up, down;

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
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        if(x > 0) up.emplace_back(x);
        else down.emplace_back(-x+1);
    }
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    if(up.empty() || (down.size() > 0 && down.back() < up.back())) swap(up, down);
}

void process()
{
    ll ans = 0;
    for(int i = up.size()-1; i >= 0; i -= k) ans += 2*(up[i]-1);
    if(down.size() == 0) ans -= (up.back()-1);
    for(int i = down.size()-1; i >= 0; i -= k) ans += 2*(down[i]-1);
    if(down.size() > 0) ans -= (down.back()-1);
    cout << ans << endl;
}

