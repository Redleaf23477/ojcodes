//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
string str;
ll mul;
ll dp[100005][101][2]; // dp[digit][rem][s] = # of ways, s=1 on edge, s=0 small already

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
    cin >> str >> mul;
}

void add_self(ll &lhs, ll rhs)
{
    lhs += rhs;
    if(lhs >= MOD) lhs -= MOD;
}

ll pos(ll x) { return (x%mul+mul)%mul; }

void process()
{
    for(int d = 0; d < str[0]-'0'; d++) dp[0][d%mul][0] += 1;
    dp[0][(str[0]-'0')%mul][1] += 1;
    for(int i = 1; i < str.size(); i++)
    {
        // s = 0
        for(int rem = 0; rem < mul; rem++)
            for(int d = 0; d < 10; d++)
                add_self(dp[i][rem][0], dp[i-1][pos(rem-d)][0]);
        // s = 1
        for(int rem = 0; rem < mul; rem++)
            add_self(dp[i][rem][1], dp[i-1][pos(rem-(str[i]-'0'))][1]);
        // s = 1 -> s = 0
        for(int rem = 0; rem < mul; rem++)
            for(int d = 0; d < str[i]-'0'; d++)
                add_self(dp[i][rem][0], dp[i-1][pos(rem-d)][1]);
    }
    cout << (dp[str.size()-1][0][0] + dp[str.size()-1][0][1] - 1 + MOD)%MOD << endl;
}

