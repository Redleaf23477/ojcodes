// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
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
    cin >> n;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

void process()
{
    ll sum = 0, zero = 0;
    for(auto x : arr)
    {
        sum += x;
        if(x == 0) zero++;
    }
    ll ans = 0;
    if(zero != 0)
    {
        ans += zero, sum += zero;
    }
    if(sum == 0)
    {
        ans++;
    }
    cout << ans << endl;
}

