// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
vector<ll> arr;

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
    cin >> n;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

const ll INF = 1e9+7;
#define min(x, y) (x > y? y : x)
#define max(x, y) (x > y? x : y)
ll ok(ll num)
{
    ll mx = INF, mn = -INF;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != -1)
        {
            mx = min(mx, arr[i]+num);
            mn = max(mn, arr[i]-num);
        }
    }
    mx = min(1e9, mx);
    mn = max(0, mn);
    if(mn > mx) return -1;
    return mx;
}

void process()
{
    ll low = 0, high = 1e9, mid, ans = -1, num = -1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != -1 && arr[i-1] != -1)
        {
            low = max(low, abs(arr[i]-arr[i-1]));
            high = min(high, max(arr[i], 1e9-arr[i]));
        }
    }
    while(low <= high)
    {
        mid = (low+high)/2;
        ll res = ok(mid);
        if(res != -1) ans = mid, num = res, high = mid-1;
        else low = mid+1;
    }
    cout << ans << " " << num << endl;
}

