//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 3003;

int n;
ll arr[N], post[N];
ll dp[N][N], mxdp[N][N];

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
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = n; i > 0; i--) post[i] = arr[i] + post[i+1];
}

int searchPost(int start, ll val)
{
    val = val+post[start+1];
    int low = 1, high = start, mid, len = 0;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(post[mid] > val) low = mid+1;
        else high = mid-1, len = start-mid+1;
    }
    return len;
}

void process()
{
    // dp[end][len_of_last_segment] = max number of executives
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
//            cout << ".. i " << i << " j " << j << endl;
            ll newLen = post[i-j+1]-post[i+1];
//            cout << "newLen " << newLen << endl;
            int mxlen = searchPost(i-j, newLen);
//            cout << "mxlen " << mxlen << endl;

            dp[i][j] = (mxdp[i-j][mxlen] == 0)? 0 : mxdp[i-j][mxlen]+1; 
            mxdp[i][j] = max(mxdp[i][j-1], dp[i][j]);
        }
        dp[i][i] = 1;
        mxdp[i][i] = max(mxdp[i][i-1], dp[i][i]);
    }
//    for(int i = 0; i <= n; i++)
//        for(int j = 0; j <= n; j++)
//            cout << dp[i][j] << " \n"[j==n];
    cout << mxdp[n][n] << endl;
}

