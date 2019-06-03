//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 110, V = 100005;
const ll INF = (1ll<<60);

ll w, n;
ll weight[N], val[N];
ll dp[N][V];

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
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> weight[i] >> val[i];
    for(int i = 0; i <= 100000; i++) dp[0][i] = INF;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
}

void process()
{
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 100000; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= val[i]) 
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j-val[i]]+weight[i]);
                if(dp[i][j] <= w) ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
}

