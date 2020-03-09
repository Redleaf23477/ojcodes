// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const int N = 502;

int n;
ll arr[N];

ll shrink[N][N];
ll dp[N];

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
    for(int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
        shrink[i][i] = arr[i];
    }
    for(int len = 2; len <= n; len++)
        for(int l = 1; l+len-1 <= n; l++)
        {
            int r = l+len-1;
            for(int m = l; m < r; m++)
                if(shrink[l][m] != 0 && shrink[l][m] == shrink[m+1][r])
                {
                    shrink[l][r] = shrink[l][m]+1; break;
                }
        }
    /*
    for(int l = 1; l <= n; l++)
        for(int r = 1; r <= n; r++)
            cout << shrink[l][r] << " \n"[r==n];
    */
}

void process()
{
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+1;
        for(int j = 1; j <= i; j++)
            if(shrink[j][i] != 0) dp[i] = min(dp[j-1]+1, dp[i]);
    }
    cout << dp[n] << endl;
}

