//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 100005;
const ll MOD = 1e9+7;
const int BLACK = 0, WHITE = 1;

int n;
vector<int> tree[N];
ll dp[2][N];

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

void mul_self(ll &lhs, ll rhs)
{
    lhs *= rhs;
    lhs %= MOD;
}

void dfs(int v, int p)
{
    // count subtree result
    for(auto c:tree[v])
    {
        if(c == p) continue;
        dfs(c, v);
        mul_self(dp[BLACK][v], dp[WHITE][c]);
        mul_self(dp[WHITE][v], dp[BLACK][c]+dp[WHITE][c]);
    }
}

void init()
{
    cin >> n;
    for(int i = 1; i <= n; i++) dp[0][i] = dp[1][i] = 1;
    for(int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        tree[x].emplace_back(y);
        tree[y].emplace_back(x);
    }
}

void process()
{
    dfs(1, 1);
    cout << (dp[BLACK][1] + dp[WHITE][1])%MOD << endl;
}

