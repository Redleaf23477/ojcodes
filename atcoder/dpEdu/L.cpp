//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 3003;

bool vis[N][N];
int n;
ll arr[N];
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
    for(int i = 0; i < n; i++) cin >> arr[i];
}

ll f(int l, int r, bool first)
{
    if(vis[l][r]) return dp[l][r];
    if(l == r) dp[l][r] = (first? 1 : -1) * arr[l];
    else if(first == true)
    {
        dp[l][r] = max(f(l+1, r, false) + arr[l], f(l, r-1, false) + arr[r]);
    }
    else
    {
        dp[l][r] = min(f(l+1, r, true) - arr[l], f(l, r-1, true) - arr[r]);
    }
    vis[l][r] = true;
    return dp[l][r];
}

void process()
{
    cout << f(0, n-1, true) << endl;
}

