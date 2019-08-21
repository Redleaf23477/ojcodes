//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 450;
const ll INF = 1ll<<60;
int n;
ll arr[N], prefix[N];
ll dp[N][N];

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
    for(int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = INF;
}

ll f(int l, int r)
{
    if(l >= r) return dp[l][r] = 0;
    if(dp[l][r] != INF) return dp[l][r];

    for(int i = l; i < r; i++)
    {
        // arr[r] merge with (arr[i] ... arr[r-1])
        dp[l][r] = min(dp[l][r], f(l, i) + f(i+1, r));
    }
    dp[l][r] += prefix[r]-prefix[l-1];
    return dp[l][r];
}

void process()
{
    cout << f(1, n) << endl;
}

