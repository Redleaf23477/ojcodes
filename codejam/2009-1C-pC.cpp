//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 110;
const ll INF = (1ll<<60);
int p, q;
ll arr[N];
ll dp[N][N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> p >> q;
    arr[0] = 0;
    for(int i = 1; i <= q; i++) cin >> arr[i];
    arr[q+1] = p+1;

    for(int i = 0; i <= q+1; i++)
        for(int j = 0; j <= q+1; j++)
            dp[i][j] = 0;
}

// top-down
ll f(int l, int r)
{
    if(r <= l) return 0;
    if(l+1 == r) return 0;
    if(dp[l][r] > 0) return dp[l][r];
    ll mn = INF;
    for(int i = l+1; i < r; i++) mn = min(mn, f(l, i)+f(i, r));
    return dp[l][r] = mn + arr[r]-arr[l]-2;
}

void process()
{
    // top down;
    // cout << f(0, q+1) << endl;

    // bottom up
    for(int len = 2; len <= q+1; len++)
    {
        for(int l = 0; l+len <= q+1; l++)
        {
            int r = l+len;
            ll mn = INF;
            for(int i = l+1; i < r; i++)
                mn = min(mn, dp[l][i]+dp[i][r]);
            dp[l][r] = mn + arr[r]-arr[l]-2;
        }
    }
    cout << dp[0][q+1] << endl;
}

