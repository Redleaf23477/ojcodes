//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1010;
const ll INF = (1ll << 60);

int vn, en, totTime, twalk;
vector<int> G[N];
ll timeCost[N], value[N];
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
    cin >> totTime;
    cin >> vn >> en >> twalk;
    for(int i = 0; i < en; i++)
    {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= vn; i++)
    {
        cin >> timeCost[i] >> value[i];
    }
    for(int i = 0; i <= totTime; i++)
        for(int j = 0; j <= vn; j++)
            dp[i][j] = INF;
}

void process()
{
    dp[timeCost[1]][1] = value[1];
    for(int t = 0; t <= totTime; t++)
    {
        for(int i = 1; i <= vn; i++)
        {
            // itself
            int prvTime = t-timeCost[i];
            if(prvTime >= 0 && dp[prvTime][i] != INF) dp[t][i] = min(dp[t][i], dp[prvTime][i]+value[i]);
            // neighbors
            for(auto c:G[i])
            {
                int prvTime = t-timeCost[c]-twalk;
                if(prvTime >= 0 && dp[prvTime][c] != INF) dp[t][i] = min(dp[t][i], dp[prvTime][c]+value[c]);
            }
        }
    }
    if(dp[totTime][1] == INF) cout << "It is a trap." << endl;
    else cout << dp[totTime][1] << endl;
}

