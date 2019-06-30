//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n, d;
vector<ll> arr;

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
    cin >> n >> d;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    vector<ll> ans;
    priority_queue<ll, vector<ll>, less<ll>> pq;

    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        ll bye = 0;
        vector<ll> gg;
        while(sum+arr[i] > d)
        {
            ll b = pq.top(); pq.pop();
            gg.push_back(b);
            bye++, sum -= b;
        }
        sum += arr[i];
        pq.push(arr[i]);
        for(auto x:gg) sum += x, pq.push(x);
        ans.push_back(bye);
    }

    for(auto x:ans) cout << x << " ";
    cout << endl;
}

