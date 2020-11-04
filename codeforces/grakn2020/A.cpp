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
vector<int> arr[3];

void init()
{
    cin >> n;
    for(int i = 0; i < 3; i++) arr[i].resize(n);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
}

void process()
{
    for(int i = 0; i < 3; i++)
    {
        vector<int> ans(n); ans[0] = arr[i][0];
        for(int j = 1; j < n; j++)
        {
            for(int k = 0; k < 3; k++)
                if(arr[k][j] != ans[j-1])
                {
                    ans[j] = arr[k][j]; break;
                }
        }
        if(ans[0] != ans[n-1])
        {
            for(auto x : ans) cout << x << " ";
            cout << endl;
            return;
        }
    }
}

