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

int r, g, b;
vector<ll> red, green, blue;

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
    cin >> r >> g >> b;
    red.resize(r);
    green.resize(g);
    blue.resize(b);
    for(auto &x : red) cin >> x;
    for(auto &x : green) cin >> x;
    for(auto &x : blue) cin >> x;
    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());
}

ll cal(ll x, ll y, ll z)
{
    return (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z);
}

ll run(vector<ll> &l, vector<ll> &m, vector<ll> &r)
{
    ll ans = 3ll*1e9*1e9;
    for(auto x : m)
    {
        auto it1 = upper_bound(l.begin(), l.end(), x);
        if(it1 == l.begin()) continue;
        auto it2 = lower_bound(r.begin(), r.end(), x);
        if(it2 == r.end()) continue;
        it1--;
        ans = min(ans, cal(*it1, x, *it2));
    }
    return ans;
}

void process()
{
    ll ans = 3ll*1e9*1e9;
    ans = min(ans, run(red, blue, green));
    ans = min(ans, run(red, green, blue));
    ans = min(ans, run(blue, red, green));
    ans = min(ans, run(blue, green, red));
    ans = min(ans, run(green, blue, red));
    ans = min(ans, run(green, red, blue));
    cout << ans << endl;
}

