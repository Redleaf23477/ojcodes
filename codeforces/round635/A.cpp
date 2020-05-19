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

ll ceil(ll x, ll y)
{
    return 1 + (x-1)/y;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        cout << b << " " << max(b, c-b+1) << " " << c << endl;
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

