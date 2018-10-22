//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 210;
const ll MOD = 1e9+7;

int n;
string str;
ll dp[N][N][N];
ll pw[N];

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
    cin >> n >> str;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) dp[i][j][k] = -1;
    pw[0] = 1;
    for(int i = 1; i <= 200; i++) pw[i] = pw[i-1]*26%MOD;
}

ll f(int rest, int l, int r)
{
    if(rest < 0) return 0;
    
    if(l > r)
    {
        return pw[rest/2];
    }

    if(dp[rest][l][r] >= 0) return dp[rest][l][r];

    if(l == r)
    {
        return dp[rest][l][r] = (f(rest-1, l+1, r-1) + 25*f(rest-2, l, r))%MOD;
    }
    else if(str[l] == str[r])
    {
        return dp[rest][l][r] = (f(rest, l+1, r-1) + 25*f(rest-2, l, r))%MOD;
    }
    else
    {
        return dp[rest][l][r] = (f(rest-1, l+1, r) + f(rest-1, l, r-1) + 24*f(rest-2, l, r))%MOD;
    }
}

void process()
{
    cout << f(n, 0, n-1) << endl;
}

