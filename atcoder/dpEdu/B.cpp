//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 1000006;

ll n, k, arr[N];
ll dp[N];

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
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        ll mn = (1ll << 60);
        for(int j = max(0ll, i-k); j < i; j++) mn = min(mn, dp[j] + abs(arr[i]-arr[j]));
        dp[i] = mn;
    }
    cout << dp[n-1] << endl;
}

