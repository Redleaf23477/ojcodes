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
void process2();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process2();
    }
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    LL h, c, t; cin >> h >> c >> t;
    if(t == h) cout << 1 << endl;
    else if(t*2 <= c+h) cout << 2 << endl;
    else
    {
        LL low = 0, high = 2e6, mid, ans = -1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(mid*h+mid*c+h < t*(2*mid+1)) high = mid-1;
            else ans = mid, low = mid+1;
        }
        double dist = 0;
        LL turn = -1;
        for(int i = -1; i <= 1; i++)
        {
            LL x = ans+i;
            double tmp = (double)(x*h+x*c+h)/(double)(2*x+1);
            double d = abs(tmp-t);
            if(turn == -1 || d < dist) dist = d, turn = 2*x+1;
        }
        cout << turn << endl;
    }
}

void process2()
{
    LL h, c, t; cin >> h >> c >> t;
    if(t == h) cout << 1 << endl;
    else if(t*2 <= c+h) cout << 2 << endl;
    else
    {
        LL x = (h-t)/(2*t-c-h);
        double dist = 0, ans = -1;
        for(int i = -1; i <= 1; i++)
        {
            LL xx = x+i;
            double tmp = (double)(xx*h + xx*c + h)/(double)(2*xx + 1);
            double dd = abs(tmp-t);
            if(ans == -1 || dd < dist) ans = 2*xx+1, dist = dd;
        }
        cout << ans << endl;
    }
}

