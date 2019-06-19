//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;

int n, cd;
ll arr[N];
ll dp[N];

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
    cin >> n >> cd;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    ll mxdp = 0;
    for(int i = 0; i < cd; i++) dp[i] = 0;
    for(int i = cd; i < n; i++)
    {
        mxdp = max(mxdp, dp[i-cd]);
        dp[i] = arr[i] + mxdp;
    }
    for(int i = n-cd; i < n; i++) mxdp = max(dp[i], mxdp);
    cout << mxdp << endl;
}

