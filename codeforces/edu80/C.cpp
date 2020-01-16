//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int M = 11;
const int N = 1003;

ll n, m;
ll dp[M][N][N];

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
}

void process()
{
    const ll MOD = 1e9+7;
    for(int a = 1; a <= n; a++)
        for(int b = a; b <= n; b++)
            dp[1][a][b] = 1;
    for(int a = 1; a <= n; a++)
        for(int b = 1; b <= n; b++)
            dp[1][a][b] += dp[1][a-1][b] + dp[1][a][b-1] - dp[1][a-1][b-1];
    
    for(int len = 2; len <= m; len++)
    {
        for(int a = 1; a <= n; a++)
            for(int b = a; b <= n; b++)
            {
                dp[len][a][b] = (dp[len-1][a][n] - dp[len-1][a][b-1] + MOD)%MOD;
                /*
                for(int af = 1; af <= a; af++)
                    for(int bf = b; bf <= n; bf++)
                        dp[len][a][b] = (dp[len][a][b] + dp[len-1][af][bf])%MOD;
                */
            }
        for(int a = 1; a <= n; a++)
            for(int b = 1; b <= n; b++)
                dp[len][a][b] = (dp[len][a][b] + dp[len][a-1][b] + dp[len][a][b-1] - dp[len][a-1][b-1] + MOD)%MOD;
    }
    cout << dp[m][n][n] << endl;
    /*
    for(int len = 1; len <= m; len++)
    {
        cout << "len = " << len << endl;
        for(int a = 1; a <= n; a++)
            for(int b = 1; b <= n; b++)
                cout << dp[len][a][b] << " \n"[b==n];
    }
    */
}

