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

const ll INF = (ll)1e9+7;

int n;
vector<ll> arr;

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
    cin >> n; arr.assign(n, 0);
    for(auto &x : arr) cin >> x;
}

ll f(int l, int r, ll sub = 0)
{
//    cerr << var(l) << var(r) << var(sub) << endl;
    ll mn = INF, mncnt = 0;
    for(int i = l; i <= r; i++)
    {
        if(arr[i]-sub < mn) mn = arr[i]-sub, mncnt = 1;
        else if(arr[i]-sub == mn) mncnt++;
    }

    int nl = -1;
    ll ans1 = mn;
    for(int i = l; i <= r; i++)
    {
        if(arr[i]-sub == mn)
        {
            if(nl != -1)
            {
                ans1 += f(nl, i-1, sub+mn);
                nl = -1;
            }
        }
        else if(nl == -1) nl = i;
    }
    if(nl != -1) ans1 += f(nl, r, sub+mn);

    return min(ans1, (ll)(r-l+1));
}

void process()
{
    int nl = -1;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            if(nl != -1)
            {
                ans += f(nl, i-1, 0);
                nl = -1;
            }
        }
        if(nl == -1) nl = i;
    }
    if(nl != -1) ans += f(nl, n-1, 0);
    cout << ans << endl;
}

