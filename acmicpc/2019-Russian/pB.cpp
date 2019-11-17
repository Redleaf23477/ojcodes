//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, k;
vector<ll> arr;
const ll INF = INT_MAX;

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
    vector<ll> cnt(k, 0);
    for(int i = 0; i < n; i++) 
    {
        ll x; cin >> x;
        cnt[x-1]++;
    }
    sort(cnt.begin(), cnt.end());
    for(auto x : cnt)
    {
        if(x == 0) continue;
        arr.push_back(x);
    }
    n = arr.size();
}

void process()
{
    ll ans = arr.back() * n;
    ll mx = 0;
    int bye = 0;
    for(ll t = n/2+(n%2); t < n; t++)
    {
        if((n-bye)%2 == 0)
            ans = min(ans, t*max(mx, (arr.back()+arr.front())));
        else
            ans = min(ans, t*max({arr.back(), mx, (arr.end()[-2]+arr.front())}));
        mx = max(mx, arr.back());
        bye++;
        arr.pop_back();
    }
    cout << ans << endl;
}

