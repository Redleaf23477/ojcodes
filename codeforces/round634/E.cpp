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

const int N = 202;

int n;
vector<int> arr, pre[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n+1);
    for(int i = 0; i < N; i++)
    {
        pre[i].resize(n+1);
        fill(pre[i].begin(), pre[i].end(), 0);
    }
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j <= n; j++)
            pre[i][j] = pre[i][j-1] + (arr[j] == i);
    }
}

void process()
{
    int ans = 0;
    for(int a = 0; a < N; a++)
    {
        for(int x = 0; x <= n; x++)
        {
            if(x > pre[a].back()) break;
            int l = lower_bound(pre[a].begin(), pre[a].end(), x) - pre[a].begin() + 1;
            int r = upper_bound(pre[a].begin(), pre[a].end(), pre[a].back()-x) - pre[a].begin() -1;
            if(l > r) break;
            for(int b = 0; b < N; b++)
            {
                ans = max(ans, x+x+pre[b][r]-pre[b][l-1]);
            }
        }
    }
    cout << ans << endl;
}

