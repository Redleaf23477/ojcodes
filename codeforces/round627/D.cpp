#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

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
    // arr : a-b > 0
    cin >> n;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
    for(auto &x : arr)
    {
        ll y; cin >> y;
        x -= y;
    }
}

void process()
{
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(auto x : arr)
    {
        ans += arr.end()-upper_bound(arr.begin(), arr.end(), -x);
        if(x > 0) ans--;
    }
    cout << ans/2 << endl;
}

