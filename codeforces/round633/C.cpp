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
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    ll mxDelta = 0, mx = arr[0];
    for(int i = 1; i < n; i++)
    {
        ll d = mx - arr[i];
        mxDelta = max(mxDelta, d);
        mx = max(mx, arr[i]);
    }
    ll ans = 0;
    for(int i = 0; i < 64; i++)
    {
        if((mxDelta >> i)&1) ans = i+1;
    }
    cout << ans << endl;
}

