// codeforce 1013E
// dp, using bottom up
#include <bits/stdc++.h>

#define endl '\n'
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef long long int ll;

const int N = 5050;
const ll INF = (1ll<<60);

int n, k;
ll h[N];
ll dp[N][N/2][2];
ll ans[N][N/2];

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
    k = (n+1)/2;
    for(int i = 1; i <= n; i++) cin >> h[i];

    for(int i = 0; i <= n; i++)
    {
        dp[i][0][0] = dp[i][0][1] = 0;
        ans[i][0] = 0;
        for(int j = 1; j <= k; j++)
        {
            dp[i][j][0] = dp[i][j][1] = INF;
            ans[i][j] = INF;
        }
    }
}

void process()
{
    // build dp
    // i = 1
    {
        dp[1][1][0] = dp[1][1][1] = max(0, h[2]-h[1]+1);
        ans[1][1] = min({ ans[1][1], dp[1][1][0], dp[1][1][1] });
    }
    // i >= 2
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j > i) break;
            if(i-3 >= 0) dp[i][j][0] = ans[i-3][j-1]+max(0, h[i-1]-h[i]+1)+max(0, h[i+1]-h[i]+1);
            if(i-2 >= j-1) 
            {
                if(j > 1)
                    dp[i][j][1] = min(dp[i-2][j-1][0], dp[i-2][j-1][1])+max(0, min(h[i-2]-1, h[i-1])-h[i]+1)+max(0, h[i+1]-h[i]+1);
                else 
                    dp[i][j][1] = min(dp[i-2][j-1][0], dp[i-2][j-1][1])+max(0, h[i-1]-h[i]+1)+max(0, h[i+1]-h[i]+1);
            }
            ans[i][j] = min({ ans[i-1][j], dp[i][j][0], dp[i][j][1] });
        }
    }

    // print ans
    for(int i = 1; i <= k; i++) cout << ans[n][i] << " "; cout << endl;
/*
    // print dp
    cout << "-------" << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            cout << "(";
            if(dp[i][j][0] == INF) cout << "x";
            else cout << dp[i][j][0];
            cout << ",";
            if(dp[i][j][1] == INF) cout << "x";
            else cout << dp[i][j][1];
            cout << ") ";
        }
        cout << endl;
    }
*/
}
