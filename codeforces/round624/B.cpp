#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long int;

struct DS
{
    int n;
    vector<ll> pa;
    void init(int _n)
    {
        n = _n;
        pa.resize(n);
        for(int i = 0; i < n; i++) pa[i] = i;
    }
    int findpa(int x)
    {
        if(x == pa[x]) return x;
        else return pa[x] = findpa(pa[x]);
    }
    bool issame(int x, int y)
    {
        return findpa(x) == findpa(y);
    }
    void uni(int x, int y)
    {
        pa[findpa(x)] = findpa(y);
    }
};

ll n, m;
vector<ll> arr;
DS ds;

void init()
{
    cin >> n >> m;
    ds.init(n);
    arr.resize(n);
    for(auto &a : arr) cin >> a;
    for(int i = 0; i < m; i++) 
    {
        ll x; cin >> x; ds.uni(x, x-1);
    }
    
}

void process()
{
    vector<pair<ll,ll>> tmp(n);
    for(int i = 0; i < n; i++)
        tmp[i] = make_pair(arr[i], i);
    sort(tmp.begin(), tmp.end());
    bool good = true;
    for(int i = 0; i < n && good; i++)
    {
        if(!ds.issame(i, tmp[i].second)) good = false;
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}

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
}