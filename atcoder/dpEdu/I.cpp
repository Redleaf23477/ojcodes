//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 3000;
int n;
double p[N];
double dp[N][N];

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
    for(int i = 1; i <= n; i++) cin >> p[i];
}

void process()
{
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0]*(1.0-p[i]);
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1.0-p[i]);
        }
    }
    double sum = 0;
    for(int j = n/2+1; j <= n; j++) sum += dp[n][j];
    cout << fixed << setprecision(10) << sum << endl;
}

