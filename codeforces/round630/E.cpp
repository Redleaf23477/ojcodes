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

const ll MOD = 998244353;

ll R, C, L, H;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> R >> C >> L >> H;
}

ll add(ll lhs, ll rhs) { return (lhs + rhs)%MOD; }
ll sub(ll lhs, ll rhs) { return (lhs - rhs + MOD)%MOD; }
ll mul(ll lhs, ll rhs) { return lhs * rhs % MOD; }

ll pw(ll x, ll p)
{
    if(p == 0) return 1;
    else if(p % 2 == 0) return pw(mul(x, x), p/2);
    else return mul(x, pw(mul(x, x), p/2));
}

void process()
{
    ll O = (H-L+1)/2, E = (H-L+1)-O;
    if(O < E) swap(O, E);
    if(R*C%2 == 1)
    {
        cout << pw(add(O, E), R*C) << endl;
    }
    else
    {
        cout << mul(add(pw(add(O, E), R*C), pw(sub(O, E), R*C)), pw(2, MOD-2)) << endl;
    }
}

