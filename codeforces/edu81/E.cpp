// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

struct Bit
{
    #define lowbit(x) (x)&(-(x))
    ll n;
    vector<ll> bit;
    void init(ll _n)
    {
        n = _n;
        bit.resize(n, 0);
    }
    void add(ll x, ll d)
    {
        for(;x<n;x+=lowbit(x)) bit[x] += d;
    }
    ll sum(ll x)
    {
        ll rtn = 0;
        for(;x;x-=lowbit(x)) rtn += bit[x];
        return rtn;
    }
};

ll n, ans;
vector<ll> arr, c, p;

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
    c.resize(n+1, 0);
    p.resize(n+1, 0);
    arr.resize(n);
    vector<ll> tmp(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> tmp[i];
    for(int i = 0; i < n; i++)
        c[arr[i]] = tmp[i], p[arr[i]] = i+1;
//    for(int i = 1; i <= n; i++) cout << c[i] << " " << p[i] << endl;

    ll sum = 0;
    for(int i = 0; i < n; i++) sum += tmp[i];
    ans = sum;
    // case 1:
    if(arr[0] != 1) ans = min(ans, tmp[0]);
    else ans = 0;
    // case 2:
    if(arr.back() != n) ans = min(ans, tmp.back());
    else ans = 0;
}

void process()
{
    if(ans == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll lmax, left, right;
    vector<ll> rmin;
    Bit lbit, rbit;
    lbit.init(n+1), rbit.init(n+1);
    // init lbit
    lmax = arr[0];
    lbit.add(arr[0], c[arr[0]]);
    // init rbit
    rmin.push_back(arr[n-1]);
    rbit.add(arr[n-1], c[arr[n-1]]);
    for(ll i = n-2; i >= 1; i--)
    {
        rbit.add(arr[i], c[arr[i]]);
        rmin.push_back(min(rmin.back(), arr[i]));
    }
    for(int i = 1; i < n-1; i++)
    {
        rbit.add(arr[i], -c[arr[i]]);
        lbit.add(arr[i], c[arr[i]]);
        lmax = max(lmax, arr[i]);
        rmin.pop_back();

        // case 1: dump to right
        left = lbit.sum(n) - lbit.sum(rmin.back());
        ans = min(ans, left);
//        cout << var(i) << "case1: " << var(left) << endl;

        // case 2: dump to left
        right = rbit.sum(lmax);
        ans = min(ans, right);
//        cout << var(i) << var(lmax) << "case2: " << var(right) << endl;
        
        // case 3: switch
        left = lbit.sum(n)-lbit.sum(i+1);
        right = rbit.sum(i+1);
//        cout << var(i) << "case3: " << var(left+right) << endl;
        ans = min(ans, left+right);
    }
    cout << ans << endl;
}

