//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
#define ll int

const int N = 5003;
const ll INF = (1ll<<30);

int n;
vector<int> arr;
ll dp[N][N][2];  // l, r, dir

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
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(arr.size() == 0 || arr.back() != x) arr.push_back(x);
    }
    n = arr.size();
}

void process()
{
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j][0] = dp[i][j][1] = INF;
    for(int i = 0; i < n; i++) dp[i][i][0] = dp[i][i][1] = 0;
    for(int len = 1; len < n; len++)
    {
        for(int i = 0; i+len < n; i++)
        {
            int j = i+len;
            dp[i][j][0] = min(dp[i+1][j][0]+(arr[i]!=arr[i+1]), dp[i+1][j][1]+(arr[i]!=arr[j]));
            dp[i][j][1] = min(dp[i][j-1][0]+(arr[j]!=arr[i]), dp[i][j-1][1]+(arr[j]!=arr[j-1]));
        }
    }
    cout << min(dp[0][n-1][0], dp[0][n-1][1]) << endl;
}

/*
4 5 |2| 1 3 5
4 |5 5| 1 3 5

4 |5| 2 1 3 5
4 |2 2| 1 3 5
*/
