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
        ll h, n, m; cin >> h >> n >> m;
        while(h > 0)
        {
            if(n > 0 && h/2 + 10 < h)
                n -= 1, h = h/2+10;
            else if(m > 0)
                m -= 1, h -= 10;
            else
                break;
        }
        if(h > 0) cout << "NO" << endl;
        else cout << "YES" << endl;
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

