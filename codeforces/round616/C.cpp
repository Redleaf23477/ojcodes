// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

const int N = 3501;

ll n, m, k;
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
    cin >> n >> m >> k;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

ll run(ll left, ll right)
{
    ll rest = m-k-1;
    ll ans = 1ll<<60;
    for(ll l = 0; l <= rest; l++)
    {
        ll r = rest-l;
        ll choice_l = arr[left+l], choice_r = arr[n-1-right-r];
        ans = min(ans, max(choice_l, choice_r));
    }
    return ans;
}

void process()
{
    if(k >= m-1)
    {
        k = m-1;
    }
    ll ans = 0;
    for(ll fl = 0; fl <= k; fl++)
    {
        ll fr = k-fl;
        ans = max(ans, run(fl, fr));
    }
    cout << ans << endl;
}

