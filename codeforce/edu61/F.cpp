//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 505;
const ll INF = 1ll<<60;

int n;
string str;
ll dp[N][N];

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
    cin >> n >> str;
}

/*
ll f(int l, int r)
{
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp[l][r] != 0) return dp[l][r];
    dp[l][r] = 1 + f(l+1, r);
    for(int i = l+1; i <= r; i++)
    {
        if(str[l] == str[i]) dp[l][r] = min(f(l+1, i)+f(i+1, r), dp[l][r]);
    }
    return dp[l][r];
}
*/

void process()
{
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 1; len <= n; len++)
    {
        for(int i = 0; i+len < n; i++)
        {
            dp[i][i+len] = 1+dp[i+1][i+len];
            for(int j = i+1; j <= i+len; j++)
            {
                if(str[i] == str[j]) dp[i][i+len] = min(dp[i][i+len], dp[i+1][j]+dp[j+1][i+len]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

