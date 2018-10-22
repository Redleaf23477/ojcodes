//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1010;

ll len, num;
ll s[N];
ll rest[N];
ll dp[N][N];

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
    string str; cin >> str >> num;
    len = str.size();
    reverse(str.begin(), str.end());
    for(int i = 0; i < len; i++) s[i] = (str[i] == '?'? 10 : str[i]-'0');
    rest[0] = 1;
    for(int i = 1; i < len; i++) rest[i] = 10*rest[i-1]%num;
}

void printDP()
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < num; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

void run_dp()
{
    const ll INF = 100;
    for(int i = 0; i < len; i++)
        for(int j = 0; j < num; j++)
            dp[i][j] = INF;
    if(s[0] == 10)
    {
        for(ll k = 0; k < 10; k++) dp[0][k%num] = min(k, dp[0][k%num]);
    }
    else
    {
        dp[0][s[0]%num] = s[0];
    }

    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(s[i] == 10)
            {
                for(int k = (i==len-1? 1:0); k < 10; k++)
                {
                    ll rst = ((j-k*rest[i])%num+num)%num;
                    if(dp[i-1][rst] != INF)
                    {
                        dp[i][j] = k; break;
                    }
                }
            }
            else
            {
                int k = s[i];
                ll rst = ((j-k*rest[i])%num+num)%num;
                if(dp[i-1][rst] != INF)
                {
                    dp[i][j] = k; 
                }
            }
        }
    }
    // printDP();
    
    // print ans
    vector<int> ans;
    int rst = 0, ok = 1;
    for(int i = len-1; i >= 0; i--)
    {
        if(dp[i][rst] == INF)
        {
            ok = 0; break;
        }
        ans.push_back(dp[i][rst]);
        rst = ((rst-dp[i][rst]*rest[i])%num+num)%num;
    }
    if(ok)
    {
        for(int i = 0; i < len; i++) cout << ans[i];
        cout << endl;
    }
    else cout << "*" << endl;
}

void process()
{
    vector<int> numArr;
    int tmp = num;
    while(tmp) numArr.push_back(tmp%10), tmp/=10;
    if(numArr.size() > len)
    {
        cout << "*" << endl; return;
    }
    else if(numArr.size() < len) run_dp();
    else
    {
        for(int i = len-1; i >= 0; i--)
        {
            if(numArr[i] > s[i])
            {
                cout << "*" << endl; return;
            }
            else if(numArr[i] < s[i]) break;
        }
        run_dp();
    }
}

