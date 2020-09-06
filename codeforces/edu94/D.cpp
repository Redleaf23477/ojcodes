// Tomioka has no friends
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;

void solve(vector<ll> &arr, int n)
{
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++)
    {
        if(mp.count(arr[i]) == 0) mp[arr[i]] = vector<int>();
        mp[arr[i]].emplace_back(i);
    }
    ll ans = 0;
    for(int j = 0; j < n; j++)
        for(int k = j+1; k < n; k++)
        {
            auto &a = mp[arr[k]], &b = mp[arr[j]];
            // i: # less than j in a
            ll i = lower_bound(a.begin(), a.end(), j) - a.begin();
            // l: # greater than k in b
            ll l = b.end() - upper_bound(b.begin(), b.end(), k);
            ans += i*l;
            //cerr << "j = " << j << ", k = " << k << " => " << i*l << endl;
        }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<ll> arr(n); for(auto &x:arr) cin >> x;
        solve(arr, n);
    }
    cout.flush();
    return 0;
}

