//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1003;
const int M = 20004;

struct Block
{
    ll w, s, v;
    bool operator < (const Block &that)
    {
        return this->w + this->s < that.w + that.s;
        
        // WA : this operator doesn't follow transitive closure
//        return this->w <= that.s && this->s < that.w;
    }
};

int n;
Block arr[N];
ll dp[N][M];

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
    for(int i = 1; i <= n; i++) cin >> arr[i].w >> arr[i].s >> arr[i].v;
    sort(arr+1, arr+1+n);
}

void process()
{
    for(int i = 1; i <= n; i++)
    {
        // both are correct
        for(int j = 0; j < M; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j-arr[i].w >= 0 && arr[i].s >= j-arr[i].w) 
                dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].w]+arr[i].v);
        }
        /*
        for(int j = 0; j < M; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j <= arr[i].s && j+arr[i].w < M) 
                dp[i][j+arr[i].w] = max(dp[i][j+arr[i].w], dp[i-1][j]+arr[i].v);
        }
        */
    }
    ll ans = 0;
    for(int i = 0; i < M; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}

