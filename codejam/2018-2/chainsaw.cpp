//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define red first
#define blue second

const int N = 505;

ll R, B;
vector<P> comb;
ll dp[N*N][N][N]; // {ball possible combinition}{bag status}

void init();
void process();

int32_t main()
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
    cin >> R >> B;
    comb.clear();
    for(int b = 0; b <= B; b++)
        for(int r = b; r >= 0; r--)
            comb.emplace_back(r, b);
    for(int i = 0; i < comb.size(); i++)
        for(int r = 0; r <= R; r++)
            for(int b = 0; b <= B; b++)
                dp[i][r][b] = 0;
}

void process()
{
    for(int c = 1; c < comb.size(); c++)
        for(int r = 0; r <= R; r++)
            for(int b = 0; b <= B; b++)
            {
                if(r == 0 && b == 0) continue;
                if(r >= comb[c].red && b >= comb[c].blue)
                    dp[c][r][b] = max(dp[c-1][r][b], dp[c-1][r-comb[c].red][b-comb[c].blue]+1);
                else 
                    dp[c][r][b] = dp[c-1][r][b];
            }
    cout << dp[comb.size()-1][R][B] << endl;
}

