//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;
int n;
ll a[N], b[N], c[N];
ll dp[N][3];

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
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
}

void process()
{
    dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }
    cout << max({ dp[n-1][0], dp[n-1][1], dp[n-1][2] }) << endl;
}

