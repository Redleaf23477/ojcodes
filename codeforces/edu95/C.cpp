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
using LL = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
vector<int> arr;

void init()
{
    cin >> n;
    arr.assign(n+4, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    vector<int> dp(n+4, 3*n);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        // kill 1, 1
        // kill 1, 2
        // kill 2, 1
        // kill 2, 2
        int pt = 0;
        for(int f = 1; f <= 2; f++)
        {
            pt += arr[i+f-1];
            for(int m = 1; m <= 2; m++)
            {
                int go = f+m;
                dp[i+go] = min(dp[i+go], dp[i]+pt);
            }
        }
    }
    cout << min({dp[n], dp[n+1], dp[n+2], dp[n+3]}) << endl;
    /*
    cerr << "dp = ";
    for(auto x : dp) cerr << x << " ";
    cerr << endl;
    */
}

