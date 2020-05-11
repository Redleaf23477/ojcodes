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
    cin >> n >> k;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    map<ll,ll> sum;
    vector<ll> mn, mx;
    for(int i = 0; i < n/2; i++)
    {
        ll s = arr[i] + arr[n-1-i];
        if(sum.count(s) == 0) sum[s] = 0;
        sum[s]++;
        mn.push_back(min(arr[i], arr[n-1-i]));
        mx.push_back(max(arr[i], arr[n-1-i]));
    }
    sort(mx.begin(), mx.end());
    sort(mn.begin(), mn.end());
    ll ans = n/2;
    for(auto p : sum)
    {
        ll s = p.first, cnt = p.second;
        ll chg = n/2 - cnt;
        /*
        cerr << var(s) << var(cnt) << var(chg) << " : "; 
        cerr << upper_bound(mx.begin(), mx.end(), s-k) - mx.begin() << ", ";
        cerr << mn.end() - lower_bound(mn.begin(), mn.end(), s) << endl;
        */
        chg += lower_bound(mx.begin(), mx.end(), s-k) - mx.begin();
        chg += mn.end() - lower_bound(mn.begin(), mn.end(), s);
        ans = min(ans, chg);
    }
    cerr.flush();
    cout << ans << endl;
    cout.flush();
}

