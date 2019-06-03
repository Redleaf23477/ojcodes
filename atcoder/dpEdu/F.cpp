//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 3003;

string s, t;
ll dp[N][N];

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
    cin >> s >> t;
}

void process()
{
    for(size_t i = 1; i <= s.size(); i++)
        for(size_t j = 1; j <= t.size(); j++)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            dp[i][j] = max({ dp[i][j], dp[i-1][j], dp[i][j-1] });
        }
    stack<char> stk;
    for(size_t i = s.size(), j = t.size(); i > 0 && j > 0;)
    {
        if(s[i-1] == t[j-1]) 
        {
            stk.push(s[i-1]); i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    while(!stk.empty()) cout << stk.top(), stk.pop();
    cout << endl;
}

