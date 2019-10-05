//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;
const ll INF = 1ll<<60;

int n;
ll h[N], c[N];
ll dp[N][3];  // dp[i][inc_height]

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i] >> c[i];
}

void process()
{
    dp[0][0] = 0, dp[0][1] = c[0], dp[0][2] = 2*c[0];
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = INF;
        for(int inc = 0; inc < 3; inc++)
        {
            int i_h = h[i]+inc;
            for(int from = 0; from < 3; from++)
            {
                if(i_h == h[i-1]+from) continue;
                dp[i][inc] = min(dp[i][inc], dp[i-1][from]+c[i]*inc);
            }
        }
    }
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}

