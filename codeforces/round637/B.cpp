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
vector<ll> arr, peak;

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
    arr.resize(n);
    peak.resize(n, 0); fill(peak.begin(), peak.end(), 0);
    for(auto &x : arr) cin >> x;
    for(int i = 1; i < n-1; i++)
    {
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
            peak[i] = 1;
    }
    /*
    cerr << "peak" << endl;
    for(int i = 0; i < n; i++) cerr << peak[i] << " ";
    cerr << endl;
    */
}

void process()
{
    ll ans = 0;
    int l = 0, r = k-1;
    ll mx = 0, sum = 0;
    for(int i = 0; i <= k-1; i++)
        sum += peak[i];
    mx = 0, ans = 0;
    while(r <= n-1)
    {
//        cerr << var(l) << var(r) << var(sum) << endl;
        ll tmp = sum - peak[l] - peak[r];
        if(tmp > mx) mx = tmp, ans = l;
        if(r == n-1) break;
        sum -= peak[l];
        l++, r++;
        sum += peak[r];
    }
    cout << mx+1 << " " << ans+1 << endl;
}

