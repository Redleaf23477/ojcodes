//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<ll> arr, pos, neg;

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
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        arr[i] = x;
        if(x < 0) neg.push_back(-x);
        else pos.push_back(x);
    }
}

void process()
{
    ll ps = 0, ns = 0, d;
    for(auto &x : pos)
    {
        x /= 2;
        ps += x;
    }
    for(auto &x : neg)
    {
        x /= 2;
        ns += x;
    }
    d = ps - ns;
    if(d > 0)
    {
        for(auto x : arr)
        {
            if(x >= 0) cout << x/2 << endl;
            else if(x%2 == 0) cout << x/2 << endl;
            else if(d > 0) {cout << x/2-1 << endl; d--;}
            else cout << x/2 << endl;
        }
    }
    else
    {
        d = -d;
        for(auto x : arr)
        {
            if(x <= 0) cout << x/2 << endl;
            else if(x%2 == 0) cout << x/2 << endl;
            else if(d > 0) { cout << x/2+1 << endl; d--; }
            else cout << x/2 << endl;
        }
    }
}

