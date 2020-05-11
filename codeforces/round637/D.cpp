// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;
using Number = string;

bool operator < (const Number &lhs, const Number &rhs)
{
    // lhs and rhs have same length
    // return lhs < rhs
    if(lhs == "-INF") return true;
    if(rhs == "-INF") return false;
    for(int i = 0; i < (int)lhs.size(); i++)
    {
        if(lhs[i] < rhs[i]) return true;
        if(lhs[i] > rhs[i]) return false;
    }
    return false;
}

const int N = 2020;

int n, k;
vector<int> digit_bars, digit_bar_cnt;
vector<int> digit, digit_cnt;
Number dp[N][N];
int nxt[N][N];

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
    digit_bars = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
    digit_bar_cnt = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    cin >> n >> k;
    digit.resize(n+1);
    digit_cnt.resize(n+1, 0);
    for(int i = 1; i <= n; i++) 
    {
        string tmp(7, '0');
        for(int j = 0; j < 7; j++) cin >> tmp[j];
        digit[i] = 0;
        for(int j = 0; j < 7; j++) 
            if(tmp[j] == '1') digit[i] |= (1<<(7-j-1)), digit_cnt[i]++;
    }
}

void process()
{
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = "-INF";
    // dp[n][k]
    for(int num = 0; num <= 9; num++)
    {
        if((digit[n] & digit_bars[num]) == digit[n])
        {
            int diff = digit_bar_cnt[num] - digit_cnt[n];
            if(diff > k) continue;
            Number tmp = Number(1, '0'+num);
            if(dp[n-1][k-diff] < tmp) 
            {
                dp[n-1][k-diff] = tmp;
                nxt[n-1][k-diff] = k;
            }
        }
    }
    for(int i = n-1; i > 0; i--)
        for(int j = k; j >= 0; j--)
        {
            if(dp[i][j] == "-INF") continue;
            for(int num = 0; num <= 9; num++)
            {
                if((digit[i] & digit_bars[num]) == digit[i])
                {
                    int diff = digit_bar_cnt[num] - digit_cnt[i];
                    if(diff > j) continue;
                    Number tmp = Number(1, '0'+num);
//                    cerr << var(i) << var(j) << var(num) << var(dp[i][j]) << var(tmp) << endl;
                    if(dp[i-1][j-diff] < tmp) 
                    {
                        dp[i-1][j-diff] = tmp;
                        nxt[i-1][j-diff] = j;
                    }
                }
            }
        }
    /*
    cerr << "dp: " << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
            cerr << dp[i][j] << " ";
        cerr << endl;
    }
    */
    if(dp[0][0] == "-INF") cout << -1 << endl;
    else 
    {
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            cout << dp[i][j];
            j = nxt[i][j];
        }
        cout << endl;
    }
}


