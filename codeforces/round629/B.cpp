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

ll n, k;

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
    cin >> n >> k;
}

void process()
{
    string ans(n, 'x');
    ll a = n-2, b = 2;
    for(ll i = 0; i < n; i++)
    {
        if(a == 0) ans[i] = 'b', b--;
        else if(b == 0) ans[i] = 'a', a--;
        else
        {
            ll rk = (b == 1? a : (a+1)*(a)/2);
            if(k > rk) ans[i] = 'b', b--, k -= rk;
            else ans[i] = 'a', a--;
        }
    }
    cout << ans << endl;
}

