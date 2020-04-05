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

const int N = 102;

int n;
ll arr[N][N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        cout << "Case #" << t+1 << ":";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
}

void process()
{
    // trace
    ll trace = 0;
    for(int i = 0; i < n; i++)
        trace += arr[i][i];
    // row
    ll row = 0;
    for(int i = 0; i < n; i++)
    {
        set<ll> s;
        for(int j = 0; j < n; j++)
        {
            if(s.count(arr[i][j]) != 0)
            {
                row++; break;
            }
            s.insert(arr[i][j]);
        }
    }
    // col
    ll col = 0;
    for(int i = 0; i < n; i++)
    {
        set<ll> s;
        for(int j = 0; j < n; j++)
        {
            if(s.count(arr[j][i]) != 0)
            {
                col++; break;
            }
            s.insert(arr[j][i]);
        }
    }
    // print
    cout << " " << trace << " " << row << " " << col << endl;
}

