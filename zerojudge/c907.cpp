//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;

int n;
ll arr[N];
ll ans[N];

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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    ll mx = 0;
    stack<pair<ll, ll> > stk;
    for(int i = 0; i < n; i++)
    {
        while(stk.size() && arr[i] < stk.top().second) 
        {
            ll idx = stk.top().first, h = stk.top().second;
            ans[idx] = (i-idx)*h;
            stk.pop();
        }
        stk.push(make_pair(i, arr[i]));
    }
    while(stk.size())
    {
        ll idx = stk.top().first, h = stk.top().second;
        ans[idx] = (n-idx)*h;
        stk.pop();
    }
    reverse(arr, arr+n);
    for(int i = 0; i < n; i++)
    {
        while(stk.size() && arr[i] < stk.top().second) 
        {
            ll idx = stk.top().first, h = stk.top().second;
            ans[n-idx-1] += (i-idx)*h;
            stk.pop();
        }
        stk.push(make_pair(i, arr[i]));
    }
    while(stk.size())
    {
        ll idx = stk.top().first, h = stk.top().second;
        ans[n-idx-1] += (n-idx)*h;
        stk.pop();
    }
    reverse(arr, arr+n);
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, ans[i]-arr[i]);
    }
    cout << mx << endl;
}

