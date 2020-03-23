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

int n, k;
vector<ll> arr;
vector<ll> pos;

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
    cin >> n >> k;
    arr.resize(n+1, 0);
    pos.resize(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
}

void process()
{
    vector<int> tmp;
    ll ans1 = 0;
    for(int i = n; i > n-k; i--)
    {
        tmp.push_back(pos[i]);
        ans1 += i;
    }
    sort(tmp.begin(), tmp.end());
    /*
    cerr << "tmp : ";
    for(auto x : tmp) cerr << x << " ";
    cerr << endl;
    */
    const ll MOD = 998244353;
    ll ans = 1;
    for(int i = 0; i < k-1; i++)
    {
        ans = ans * (tmp[i+1]-tmp[i]) % MOD;
    }
    cout << ans1 << " " << ans << endl;
}

