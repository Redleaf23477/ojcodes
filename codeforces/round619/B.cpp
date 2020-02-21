// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

const ll INF = 1e9;

ll n;
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

ll ok(ll delta)
{
    ll up = 2*INF, down = -2*INF;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != -1) continue;
        if(i > 0 && arr[i-1] != -1)
        {
            up = min(up, arr[i-1]+delta);
            down = max(down, arr[i-1]-delta);
        }
        if(i < n-1 && arr[i+1] != -1)
        {
            up = min(up, arr[i+1]+delta);
            down = max(down, arr[i+1]-delta);
        }
    }
    if(down <= up)
    {
        if(up <= INF) return up;
        else if(down >= 0) return down;
        else return 2*INF;
    }
    else
    {
        return -1;
    }
}

bool allneg1()
{
    return *max_element(arr.begin(), arr.end()) == -1;
}

void process()
{
    if(allneg1()) { cout << 0 << " " << 0 << endl; return; }
    ll low = 0, high = INF, mid, ans = -1, num = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        ll res = ok(mid);
        if(res != -1) ans = mid, num = res, high = mid-1;
        else low = mid+1;
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != -1 && arr[i-1] != -1)
            ans = max(ans, abs(arr[i]-arr[i-1]));
    }
    cout << ans << " " << num << endl;
}

