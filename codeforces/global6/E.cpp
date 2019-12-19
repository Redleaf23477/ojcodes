//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, m;
vector<ll> arr;

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
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
}

void process()
{
    vector<ll> mile(n, 0);
    map<pair<int,int>, int> mp;
    int i, j, k;
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += arr[i];
    while(m--)
    {
        cin >> i >> j >> k;
        i--, k--;
        auto p = make_pair(i, j);
        if(mp.count(p) == 1)
        {
            if(mile[mp[p]] <= arr[mp[p]]) ans++;
            mile[mp[p]]--;
            mp.erase(p);
        }
        if(k != -1)
        {
            mp[p] = k;
            mile[k]++;
            if(mile[k] <= arr[k]) ans--;
        }
        cout << ans << endl;
    }
}

