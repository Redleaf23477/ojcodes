//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

bool cmp (const P &a, const P &b)
{
    return a.first-a.second > b.first-b.second;
}

const int N = 100005;

int n;
ll m;
P arr[N];

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
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n, cmp);
}

void process()
{
    ll tot = 0, cnt = 0;
    for(int i = 0; i < n; i++) tot += arr[i].first;
    for(cnt = 0; cnt < n && tot > m; cnt++)
    {
        tot -= arr[cnt].first - arr[cnt].second;
    }
    if(tot > m) cout << -1 << endl;
    else cout << cnt << endl;
}

