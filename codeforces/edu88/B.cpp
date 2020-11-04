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

void init()
{
}

void process()
{
    int R, C, x, y ; cin >> R >> C >> x >> y;
    vector<vector<char>> arr(R, vector<char>(C));
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> arr[i][j];
    y = min(y, 2*x);
    int ans = 0;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] == '*') continue;
            if(c+1 < C && arr[r][c+1] == '.') ans += y, c++;
            else ans += x;
        }
    cout << ans << endl;
}

