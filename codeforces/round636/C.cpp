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

const int N = 200005;
const ll INF = 1ll << 60;

int n;
vector<ll> arr;

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
    arr.clear();
    ll val, pos;
    cin >> val; pos = (val > 0);
    for(int i = 1; i < n; i++) 
    {
        ll x; cin >> x;
        if((x > 0) == pos)
        {
            val = max(val, x);
        }
        else
        {
            arr.push_back(val);
            val = x;
            pos = (val > 0);
        }
    }
    arr.push_back(val);
}

void process()
{
    /*
    cerr << "arr" << endl;
    for(auto x : arr) cerr << x << " ";
    cerr << endl;
    */
    ll ans = 0;
    for(auto x : arr) ans += x;
    cout << ans << endl;
}
