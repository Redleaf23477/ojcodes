//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 300005;

int n, q;
ll arr[N];
ll sum;

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
    for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    sort(arr, arr+n);
}

void process()
{
    cin >> q;
    while(q--)
    {
        ll x; cin >> x;
        cout << sum - arr[n-x] << endl;
    }
}

