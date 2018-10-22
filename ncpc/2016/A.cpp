//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 110;
int n;
ll arr[N][N];
ll dp[N][N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n && n)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            cin >> arr[i][j];
    }
}

void process()
{
    for(int i = 0; i < n; i++) dp[n-1][i] = arr[n-1][i];
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
            dp[i][j] = arr[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    }
    cout << dp[0][0] << endl;
}

