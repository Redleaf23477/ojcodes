//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll n, d;
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
    priority_queue<ll, vector<ll>, greater<ll>> trash;

    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        while(!trash.empty() && !pq.empty() && trash.top() < pq.top())
        {
            ll t = trash.top(); trash.pop();
            ll p = pq.top(); pq.pop();
            sum -= p, sum += t;
            trash.push(p), pq.push(t);
        }
        while(sum + arr[i] > d)
        {
            ll p = pq.top(); pq.pop();
            sum -= p;
            trash.push(p);
        }
        pq.push(arr[i]);
        sum += arr[i];
        ans.push_back(trash.size());
    }

    for(auto x:ans) cout << x << " ";
    cout << endl;
}

