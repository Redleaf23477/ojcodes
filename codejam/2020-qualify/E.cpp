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

const int N = 52;

int n, sum;
int arr[N][N];

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
    cin >> n >> sum;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;
}

void construct()
{
    // diagonal
    int q = sum / n, r = sum % n;
    if(r == 0)
    {
        vector<int> num;
        num.push_back(q);
        for(int i = 1; i <= n; i++)
        {
            if(i == q) continue;
            num.push_back(i);
        }
        for(int i = 0; i < n; i++)
        {
            for(int r = 0, c = i; r < n; r++, c = (c+1)%n)
                arr[r][c] = num[i];
        }
    }
    else
    {
        // fill q, q+1
        for(int i = 0; i < n; i++)
            arr[i][i] = q;
        for(int i = 0; i < r; i++)
            arr[i][i] = (q+1);
        for(int i = 0, j = 1; i < r; i++, j = (j+1)%r)
            arr[i][j] = q;
        for(int i = r, j = 1; i < n; i++, j = (j+1)%(n-r))
            arr[i][j+r] = (q+1);
        // numbers other than q, q+1
        vector<int> num;
        for(int i = 1; i <= n; i++)
        {
            if(i == q || i == q+1) continue;
            num.push_back(i);
        }
        // fill smaller square
        for(int f = 3; f <= min(r, n-r); f++)
        {
            for(int i = 0, j = f-1; i < r; i++, j = (j+1)%r)
                arr[i][j] = num.back();
            for(int i = r, j = f-1; i < n; i++, j = (j+1)%(n-r))
                arr[i][j+r] = num.back();
            num.pop_back();
        }
        // fill right
        for(int _i = 0; _i < (int)num.size(); _i++)
        {
            int x = num[_i];
            for(int i = 0, j = _i; i < r; i++, j = (j+1)%(n-r))
                arr[i][r+j] = x;
        }
        // fill down
        for(int _i = 0; _i < (int)num.size(); _i++)
        {
            int x = num[_i];
            for(int i = _i, j = 0; j < r; i++, j++)
                arr[r+(i+1)%(n-r)][j%r] = x;
        }
        // fill big matrix
        for(int i = r; i < n; i++)
        {
            int zidx = -1, toFill = 0;
            vector<bool> cnt(n+1, 0);
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] == 0) zidx = j;
                else cnt[arr[i][j]] = true;
            }
            for(int j = 1; j <= n; j++)
                if(cnt[j] == false)
                    toFill = j;
            arr[i][zidx] = toFill;
        }
    }
    // check
    /*
    cout.flush();
    bool good = true;
    for(int i = 0; i < n; i++)
    {
        vector<bool> cnt(n, 0);
        for(int j = 0; j < n; j++)
        {
            if(cnt[arr[i][j]-1]) good = false;
            cnt[arr[i][j]-1] = true;
        }
    }
    for(int i = 0; i < n; i++)
    {
        vector<bool> cnt(n, 0);
        for(int j = 0; j < n; j++)
        {
            if(cnt[arr[j][i]-1]) good = false;
            cnt[arr[j][i]-1] = true;
        }
    }
    if(!good) cout << "invalid martix" << endl;
    */
}

bool possible()
{
    int q = sum / n, r = sum % n;
}

void process()
{
    if(possible())
    {
        cout << "POSSIBLE" << endl;
        construct();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cout << arr[i][j] << " \n"[j==n-1];
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

