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

ll n;
map<ll,ll> mp;
#define val first
#define cnt second

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
    cin >> n;
    mp.clear();
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        if(mp.count(x) == 0) mp[x] = 0;
        mp[x]++;
    }
}

void process()
{
    if(mp.size() == 1)
    {
        if(n == 1) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }
    ll mx = 0;
    for(auto p : mp)
    {
        mx = max(mx, p.cnt);
    }
    ll ans = 0;
    if(mx <= (ll)mp.size()-1) ans = mx;
    else ans = min(mx-1, (ll)mp.size());
    cout << ans << endl;
}

