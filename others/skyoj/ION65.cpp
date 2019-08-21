//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 10004, M = 13;

int n, k;
ll arr[N];
ll dp[N][M];

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
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
}

void process()
{
    const ll INF = (1ll<<60);
    for(int i = 1; i <= n; i++) dp[i][0] = INF;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = INF;
            for(int sz = 1; sz <= i; sz++)
                dp[i][j] = min(dp[i-sz][j-1]+sz*arr[i], dp[i][j]);
        }
    }
    cout << dp[n][k] << endl;
}

