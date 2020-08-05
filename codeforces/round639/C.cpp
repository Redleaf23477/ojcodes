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

ll mod(ll lhs, ll rhs)
{
    return (lhs%rhs+rhs)%rhs;
}

ll n;
vector<ll> arr;

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
    for(int i = 0; i < n; i++)
    {
        arr[i] = mod(arr[i]+i, n);
    }
    set<ll> s(arr.begin(), arr.end());
    if((int)s.size() == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}

