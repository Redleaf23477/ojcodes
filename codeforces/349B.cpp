//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

struct Num
{
    ll digitNum;
    vector<int> digitCnt;
    void push_back(int digit)
    {
        digitNum++;
        digitCnt[digit]++;
    }
    bool operator < (const Num &that)
    {
        if(digitNum != that.digitNum) return digitNum < that.digitNum;
        for(int i = 9; i > 0; i--)
            if(digitCnt[i] != that.digitCnt[i]) return digitCnt[i] < that.digitCnt[i];
        return true;
    }
    Num():digitNum(0), digitCnt(10, 0){}
};

ostream& operator << (ostream &out, Num &n)
{
    if(n.digitNum == 0) out << -1;
    else
    {
        for(int i = 9; i > 0; i--)
            for(int j = 0; j < n.digitCnt[i]; j++)
                out << i;
    }
    return out;
}

Num max(Num lhs, Num rhs)
{
    if(lhs < rhs) return rhs;
    else return lhs;
}

const int N = 1000006;

ll v;
ll arr[10];
Num dp[N];

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
    cin >> v;
    for(int i = 1; i <= 9; i++) cin >> arr[i];
}

void process()
{
    for(int i = 1; i <= 9; i++)
        for(ll j = 0; j <= v; j++)
        {
            if(j >= arr[i] && dp[j-arr[i]].digitNum >= dp[j].digitNum-1)
            {
                dp[j] = dp[j-arr[i]];
                dp[j].push_back(i);
            }
        }
    Num ans;
    for(int j = 0; j <= v; j++)
        ans = max(ans, dp[j]);
    cout << ans << endl;
}

