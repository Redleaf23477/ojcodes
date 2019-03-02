//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 200005;

ll n, m;
ll arr[N];

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
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    reverse(arr, arr+n);
}

bool ok(ll day)
{
    ll cnt = 0;
    int i = 0, cup = 1;
    vector<ll> prvcof(day);
    vector<ll> prvcnt(day);
    while(i < n)
    {
        for(int d = 0; d < day; d++)
        {
            if(cup > 1) cnt -= prvcnt[d];
            if(cup > 1) cnt += max(0ll, prvcof[d]-(cup-1)+1);
            cnt += max(0ll, arr[i]-cup+1);
            if(cnt >= m) return true;
            prvcnt[d] = max(0ll, arr[i]-cup+1);
            prvcof[d] = arr[i];
            i++;
            if(i >= n) break;
        }
        cup++;
    }
    return false;
}

void process()
{
    ll low = 1, high = n, mid, ans = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}

