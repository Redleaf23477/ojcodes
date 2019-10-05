//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<ll> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

bool dp[2][3000];

bool ok()
{
    for(int i = 0; i <= 2048; i++) dp[0][i] = dp[1][i] = false;
    dp[1][0] = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= 2048; j++) dp[i%2][j] = false;
        for(int j = 0; j <= 2048; j++)
        {
            if(j-arr[i] >= 0 && dp[(i+1)%2][j-arr[i]] == true) dp[i%2][j] = true;
            if(dp[(i+1)%2][j] == true) dp[i%2][j] = true;
        }
    }
    return dp[(n-1)%2][2048];
}

void process()
{
    if(ok()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

