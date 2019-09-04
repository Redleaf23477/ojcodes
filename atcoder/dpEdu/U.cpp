//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 16;
const ll INF = 1ll<<60;
int n;
ll arr[N][N];
ll points[(1<<N)];
ll dp[(1<<N)];

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
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<int> ones;
    for(int mask = 0; mask < (1<<n); mask++)
    {
        ones.clear();
        for(int i = 0; i < n; i++)
            if((mask>>i)&1) ones.emplace_back(i);
        for(int i = 0; i < ones.size(); i++)
            for(int j = i+1; j < ones.size(); j++)
                points[mask] += arr[ones[i]][ones[j]];
    }
}

/*
ll f(int mask)
{
    if(dp[mask] != -INF) return dp[mask];
    // mask => group1 | group2
    // dp[mask] = max(dp[group1] + points[group2])
    vector<int> ones;
    for(int i = 0; i < n; i++)
        if((mask>>i)&1) ones.emplace_back(i);
    for(int m = 1; m < (1<<ones.size()); m++)
    {
        int group2 = 0;
        for(int i = 0; i < ones.size(); i++)
            if((m>>i)&1) group2 |= (1<<ones[i]);
        int group1 = mask ^ group2;
        dp[mask] = max(dp[mask], f(group1) + points[group2]);
    }
    return dp[mask];
}
*/

void process()
{
    vector<int> ones;
    for(int mask = 0; mask < (1<<n); mask++)
    {
        ones.clear();
        for(int i = 0; i < n; i++)
            if((mask>>i)&1) ones.emplace_back(i);
        for(int m = 1; m < (1<<ones.size()); m++)
        {
            int group2 = 0;
            for(int i = 0; i < ones.size(); i++)
                if((m>>i)&1) group2 |= (1<<ones[i]);
            int group1 = mask ^ group2;
            dp[mask] = max(dp[mask], dp[group1] + points[group2]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
}

