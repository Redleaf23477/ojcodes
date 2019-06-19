//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll n, m, ta, tb, k;
vector<ll> a, b;

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
    cin >> n >> m >> ta >> tb >> k;
    a.resize(n);
    b.resize(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void process()
{
    if(k >= m || k >= n) cout << -1 << endl;
    else
    {
        ll ans = 0;
        for(int i = 0; i < n && i <= k; i++)
        {
            int left = k-i;
            int j = lower_bound(b.begin(), b.end(), a[i]+ta)-b.begin();
            if(j+left >= b.size()) { ans = -1; break; }
            ans = max(ans, b[j+left]+tb);
        }
        cout << ans << endl;
    }
}

