//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 1010;
const ll MOD = 1e9+7;
int R, C;
char maze[N][N];
ll dp[N][N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> R >> C;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> maze[r][c];
}

void process()
{
    dp[0][0] = 1;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(maze[r][c] != '.') continue;
            if(r > 0 && maze[r-1][c] == '.') dp[r][c] = (dp[r][c] + dp[r-1][c])%MOD;
            if(c > 0 && maze[r][c-1] == '.') dp[r][c] = (dp[r][c] + dp[r][c-1])%MOD;
        }
    cout << dp[R-1][C-1] << endl;
}

