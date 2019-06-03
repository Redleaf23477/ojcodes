//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 1000006;

ll n, arr[N];
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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    dp[0] = 0, dp[1] = abs(arr[1]-arr[0]);
    for(int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i-1] + abs(arr[i]-arr[i-1]), dp[i-2] + abs(arr[i]-arr[i-2]));
    }
    cout << dp[n-1] << endl;
}

