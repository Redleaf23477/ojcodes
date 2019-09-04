//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 3030;
const ll MOD = 1e9+7;

int n;
char arr[N];
ll dp[N][N]; // dp[i][j] = # of considering first n op, ended with j

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
    cin >> n;
    for(int i = 1; i < n; i++) cin >> arr[i];
    dp[0][0] = 1;
}

void add_self(ll &lhs, ll rhs)
{
    lhs += rhs;
    if(lhs > MOD) lhs -= MOD;
}

void process()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= i; j++) add_self(dp[i-1][j], dp[i-1][j-1]);
        for(int j = 0; j <= i; j++)
        {
            if(arr[i] == '>')
            {
                if(j== 0) 
                    add_self(dp[i][j], dp[i-1][i]);
                else
                    add_self(dp[i][j], (dp[i-1][i]-dp[i-1][j-1]+MOD)%MOD);
//                for(int k = j; k <= i; k++) add_self(dp[i][j], dp[i-1][k]);
            }
            else
            {
                if(j != 0) add_self(dp[i][j], dp[i-1][j-1]);
//                for(int k = 0; k < j; k++) add_self(dp[i][j], dp[i-1][k]);
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j < n; j++) add_self(ans, dp[n-1][j]);
    cout << ans << endl;
}

