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

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int p = 0, c = 0;
        bool good = true;
        while(n--)
        {
            int x, y; cin >> x >> y;
            if(x < p) good = false;
            if(y < c) good = false;
            if(x-p < y-c) good = false;
            p = x, c = y;
        }
        if(good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
}

