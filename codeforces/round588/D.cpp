//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
map<ll,ll> mp;
#define a first
#define b second
set<ll> dup;

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

bool isSubset(ll a, ll b)
{
    for(ll i = 0; i < 60; i++)
    {
        if(((b>>i)&1)==1 && ((a>>i)&1)==0) return false;
    }
    return true;
}

void init()
{
    cin >> n;
    vector<ll> arr(n), brr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];
    for(int i = 0; i < n; i++)
    {
        ll a = arr[i], b = brr[i];
        if(mp.count(a) == 0) mp[a] = 0;
        else dup.insert(a);
        mp[a] += b;
    }
}

void process()
{
    ll ans = 0;
    for(auto u : dup) ans += mp[u];
    for(auto v : mp)
    {
        if(dup.count(v.a) != 0) continue;
        for(auto u : dup)
        {
            if(isSubset(u, v.a)) { ans += v.b; break; }
        }
    }
    cout << ans << endl;
}

