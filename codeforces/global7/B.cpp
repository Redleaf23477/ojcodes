// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

int n;
vector<ll> b;

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
    cin >> n;
    b.resize(n);
    for(auto &x : b) cin >> x;
}

void process()
{
    vector<ll> a(n, 0);
    a[0] = b[0]+0;
    ll mx = max(0ll, a[0]);
    for(int i = 1; i < n; i++)
    {
        a[i] = b[i]+mx;
        mx = max(mx, a[i]);
    }
    for(auto x : a) cout << x << " ";
    cout << endl;
}

