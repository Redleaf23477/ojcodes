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
using P = pair<int,int>;

struct Event
{
    int idx, first, second;
};

bool cmp(const Event &lhs, const Event  &rhs)
{
    if(lhs.second != rhs.second) return lhs.second < rhs.second;
    else return lhs.first < rhs.first;
}

const int N = 1003;
const int INF = 7122;

int n;
Event arr[N];
P dp[N][N]; // dp[i][i] = for prefix 1~i, one guy get the i-th activity
P back[N][N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr[0] = (Event){0, -1, -1};
    for(int i = 1; i <= n; i++) 
    {
        arr[i].idx = i;
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr+1, arr+1+n, cmp);
    /*
    cout << "activity = " << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << i << " : " << arr[i].first << " " << arr[i].second << endl;
    }
    */
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            back[i][j] = dp[i][j] = P(INF, INF);
}

void process()
{
    P invalid(INF, INF);
    back[0][0] = dp[0][0] = P(0,0);
    for(int i = 1; i <= n; i++)
    {
        // dp[i][i] <= dp[i-1][x] such that dp[i-1][x] is valid & (x,i) doesn't overlap
        for(int j = 0; j < i; j++)
        {
            if(dp[i-1][j] != invalid && dp[i-1][j].first <= arr[i].first)
            {
                if(dp[i-1][j].second < dp[i][j].second)
                {
                    dp[i][i] = P(arr[i].second, dp[i-1][j].second);
                    back[i][i] = P(i-1, j);
                }
            }
        }
        // dp[i][x] <= dp[i-1][x] such that dp[i-1][x] is valid & (i-1, i) doesn't overlap
        for(int j = 0; j < i; j++)
        {
            if(dp[i-1][j] != invalid && dp[i-1][j].second <= arr[i].first)
            {
                if(dp[i-1][j].first < dp[i][j].first)
                {
                    dp[i][j] = P(dp[i-1][j].first, arr[i].second);
                    back[i][j] = P(i-1, j);
                }
            }
        }
    }
    /*
    cout << "dp = " << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            cout << "(" << dp[i][j].first << "," << dp[i][j].second << ")";
        cout << endl;
    }
    */
    P ans = invalid;
    for(int i = 0; i <= n; i++)
        if(dp[n][i] != invalid)
        {
            ans = P(n, i); break;
        }
    if(ans != invalid)
    {
        string str, str2(n, 'X');
        do
        {
            if(back[ans.first][ans.second].second == ans.second) str.push_back('C');
            else str.push_back('J');
            ans = back[ans.first][ans.second];
        } while(ans != P(0, 0));
        reverse(str.begin(), str.end());
        for(int i = 0; i < n; i++)
        {
            str2[arr[i+1].idx-1] = str[i];
        }
        cout << str2 << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}


