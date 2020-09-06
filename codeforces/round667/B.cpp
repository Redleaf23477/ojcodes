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

void process()
{
    ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
    ll da = a-x, db = b-y;
    if(n >= da+db) cout << x*y << endl;
    else
    {
        ll ans = a*b;
        if(n >= da) ans = min(x*(b-(n-da)), ans);
        else ans = min((a-n)*b, ans);
        if(n >= db) ans = min((a-(n-db))*y, ans);
        else ans = min(a*(b-n), ans);
        cout << ans << endl;
    }
}

