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

ll a, b, q;

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
    cin >> a >> b >> q;
    if(a > b) swap(a, b);
    // a small b large
}

ll f(ll n, ll a, ll b, ll lcm)
{
    ll r = n/lcm;
    ll full = max(0ll, r);
    ll ans = b * full;
    n -= full*lcm;
    ans += min(b, n+1);
    return ans;
}

void process()
{
    // x % a % b == x % a
    ll l, r;
    ll lcm = a*b/__gcd(a, b);
    while(q--)
    {
        cin >> l >> r;
        ll ans = f(r, a, b, lcm) - f(l-1, a, b, lcm);

        /*
        for(ll x = l; x < tmp_l*lcm; x++)
            if(x%b%a == x%a) ans++;
        for(ll x = tmp_r*lcm; x <= r; x++)
            if(x%b%a == x%a) ans++;
        */

        cout << r-l+1-ans << " ";
    }
    cout << endl;
}
