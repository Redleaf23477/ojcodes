//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 101, M = 100005;
const ll MOD = 1e9+7;

int n, candyNum;
int arr[N];
ll dp[N][M]; // dp[n][m] = distribute m candies to n children

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
    cin >> n >> candyNum;
    for(int i = 1; i <= n; i++) cin >> arr[i];
}

void process()
{
    for(int j = 0; j <= min(arr[1], candyNum); j++) dp[1][j] = 1;
    for(int i = 2; i <= n; i++)
    {
        vector<ll> pSum(candyNum+1); pSum[0] = dp[i-1][0];
        for(int j = 1; j <= candyNum; j++) pSum[j] = (pSum[j-1] + dp[i-1][j])%MOD;
        for(int j = 0; j <= candyNum; j++)
        {
            // sum of (dp[i-1][max(0, j-arr[i])] ... dp[i-1][j])
            if(arr[i] >= j) dp[i][j] = pSum[j];
            else dp[i][j] = (pSum[j] - pSum[j-arr[i]-1] + MOD)%MOD;
            /*
            for(int k = 0; k <= min(j, arr[i]); k++)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
            }
            */
        }
    }
    cout << dp[n][candyNum] << endl;
}

