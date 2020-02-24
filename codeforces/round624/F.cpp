#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long int;
using P = pair<ll, ll>;
#define x first
#define v second

struct BIT
{
    int n;
    vector<ll> bit;
    inline int lowbit(int x) { return x & -x; }
    void init(int _n)
    {
        n = _n;
        bit.resize(n);
        fill(bit.begin(), bit.end(), 0);
    }
    void add(int x, ll v)
    {
        for(; x < n; x += lowbit(x)) bit[x] += v;
    }
    ll query(int x)
    {
        ll ans = 0;
        for(; x; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
};

ll n, vNum;
vector<P> arr;

void init()
{
    cin >> n;
    arr.resize(n);
    set<ll> s;
    map<ll,ll> mp;
    for(int i = 0; i < n; i++) cin >> arr[i].x;
    for(int i = 0; i < n; i++) { cin >> arr[i].v; s.insert(arr[i].v); }
    int idx = 1;
    for(auto x : s) mp[x] = idx++;
    vNum = idx;
    for(auto &x : arr) x.v = mp[x.v];

}

void process()
{
    BIT sum, cnt;
    sum.init(vNum+1), cnt.init(vNum+1);
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(auto x : arr)
    {
        ll s = sum.query(x.v);
        ll c = cnt.query(x.v);
        ans += x.x*c - s;
        sum.add(x.v, x.x);
        cnt.add(x.v, 1);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
}