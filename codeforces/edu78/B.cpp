//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll x; 

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
    ll a, b; cin >> a >> b;
    x = abs(a-b);
}

inline ll f(ll n) { return n*(n+1)/2; }

ll bs(ll d)
{
    ll low = 0, high = 1e9, mid, ans = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(f(mid) >= d) ans = mid, high = mid-1;
        else low = mid+1;
    }
    return ans;
}

void process()
{
    ll n = bs(x);
    while(x%2 != f(n)%2) n++;
    cout << n << endl;
}

