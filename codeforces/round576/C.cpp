//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

ll n, I;
vector<ll> data;  // data[i] = # of i
vector<ll> pre, suf;

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
    cin >> n >> I;
    vector<ll> arr(n);
    set<ll> s;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    ll idx = 0;
    for(auto x : s) mp[x] = idx++;
    data.resize(idx, 0);
    for(auto x : arr) data[mp[x]]++;
    pre = suf = data;
    for(size_t i = 1; i < pre.size(); i++) pre[i] += pre[i-1];
    for(int i = pre.size()-2; i >= 0; i--) suf[i] += suf[i+1];
}

ll ceillog(ll x)
{
    ll K = 1, k = 0;
    while(x > K) K*=2, k++;
    return k;
}

ll bs(ll cnt)
{
    ll l = 1, r = cnt, mid, ans = -1;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(n*ceillog(mid) <= 8*I) l = mid+1, ans = mid;
        else r = mid-1;
    }
    return ans;
}

ll exchangeElements(int l, int r)
{
    ll ans = 0;
    if(l > 0) ans += pre[l-1];
    if(r < suf.size()-1) ans += suf[r+1];
    return ans;
}

void process()
{
    ll ans = n;
    for(int l = 0; l < data.size(); l++)
    {
        ll len = bs(data.size()-l);
        ans = min(ans, exchangeElements(l, l+len-1));
    }
    cout << ans << endl;
}

