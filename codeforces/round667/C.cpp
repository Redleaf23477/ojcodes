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

void print(ll x, ll y, ll d, ll n)
{
    for(ll i = x; i <= y && n > 0; i += d, n--)
    {
        cout << i << " ";
    }
    for(ll i = x-d; i > 0 && n > 0; i -= d, n--)
    {
        cout << i << " ";
    }
    for(ll i = y+d; n > 0; i += d, n--)
    {
        cout << i << " ";
    }
    cout << endl;
}

void process()
{
    ll n, x, y; cin >> n >> x >> y;
    ll dif = y-x;

    for(ll d = 1; d <= dif; d++)
    {
        if(dif % d != 0) continue;
        if(dif / d + 1 <= n)
        {
            print(x, y, d, n); break;
        }
    }
}
