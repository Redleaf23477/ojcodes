//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int M = 21;
const ll INF = 1ll<<60;

int n, m;
ll cnt[M][M];
ll dp[(1<<M)];
string str;

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
    cin >> n >> m >> str;
    for(int i = 1; i < n; i++)
    {
        int a = str[i-1]-'a', b = str[i]-'a';
        cnt[a][b]++, cnt[b][a]++;
    }
    for(int i = 0; i < (1<<m); i++) dp[i] = INF;
}

bool inMask(int msk, int x) { return (msk>>x)&1; }

void process()
{
    dp[0] = 0;
    for(int msk = 0; msk < (1<<m); msk++)
    {
        // x : newly inserted to keyboard
        for(int x = 0; x < m; x++)
        {
            int newMsk = msk | (1<<x);
            int posx = __builtin_popcount(msk)+1;
            if(inMask(msk, x)) continue;
            ll tmp = dp[msk];
            for(int y = 0; y < m; y++)
            {
                if(y == x) continue;
                if(inMask(msk, y)) tmp += cnt[x][y] * posx;
                else tmp -= cnt[x][y] * posx;
            }
            dp[newMsk] = min(dp[newMsk], tmp);
        }
    }
    cout << dp[(1<<m)-1] << endl;
}

