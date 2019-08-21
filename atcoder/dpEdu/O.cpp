//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 23;
const ll MOD = 1e9+7;

int n;
int arr[N][N];
ll dp[N][(1<<N)];
ll lookup[(1<<N)];

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
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++) lookup[1<<i] = i;
}

void add_self(ll &lhs, ll rhs)
{
    lhs += rhs;
    if(lhs >= MOD) lhs -= MOD;
}

#define lowbit(x) (x)&(-x)

void process()
{
    dp[0][0] = 1;
    for(int man = 1; man <= n; man++)
        for(int mask = 0; mask < (1<<n); mask++)
            for(int m = mask; m > 0; m -= lowbit(m))
            {
                int woman = lowbit(m), idx = lookup[woman];
                if(arr[man][idx]) 
                    add_self(dp[man][mask], dp[man-1][mask^woman]);
            }
    cout << dp[n][(1<<n)-1] << endl;
}

