//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 5050;
const ll INF = (1ll<<60);

int n;
ll h[N];
ll dp[N][N/2][2];
ll mndp[N][N/2];

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
    for(int i = 1; i <= n; i++) cin >> h[i];
    memset(dp, -1, sizeof(dp));
}

ll g(int n, int k)
{
    if(n <= 0 || k <= 0) return INF;
    else return mndp[n][k];
}

ll f(int n, int k, bool b)
{
    if(k == 0) return 0;
    if(n <= 0) return INF;
    if(dp[n][k][b] != -1) return dp[n][k][b];

    ll smashLeft, rHeight, smashRight;
    smashLeft = (h[n-1] >= h[n]? h[n-1]-h[n]+1 : 0);
    rHeight = (b? min(h[n+2]-1, h[n+1]) : h[n+1]);
    smashRight = (rHeight >= h[n]? rHeight-h[n]+1 : 0);

    ll mn = min( f(n-2, k-1, 1), g(n-3, k-1) );
    if(mn == INF) return dp[n][k][b] = INF;
    else return dp[n][k][b] = mn + smashLeft + smashRight;
}

void process()
{
    int k = (n+1)/2;
    for(int i = 1; i <= k; i++) 
    {
        mndp[0][i] = INF;
        for(int j = 1; j <= n; j++) 
        {
//            if(f(j, i, 0) == INF) cout << "x ";
//            else cout << f(j, i, 0) << " ";
            mndp[j][i] = min(mndp[j-1][i], f(j, i, 0));
        }
//        cout << " || ";
        cout << mndp[n][i] << " ";
//        cout << endl;
    }
    cout << endl;
}

