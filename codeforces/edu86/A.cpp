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

ll x, y;
ll a, b;

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
    cin >> x >> y;
    cin >> a >> b;
}

void process()
{
    if(a*2 <= b)
    {
        cout << a*(abs(x)+(abs(y))) << endl;
    }
    else
    {
        ll cst = 0;
        if(x*y > 0)
        {
            x = abs(x), y = abs(y);
            ll mn = min(x, y);
            cst += b * mn;
            x -= mn, y -= mn;
        }
        cst += a * (abs(x) + abs(y));
        cout << cst << endl;
    }
}

