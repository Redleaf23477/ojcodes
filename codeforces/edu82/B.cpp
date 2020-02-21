// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n, g, b;

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
    cin >> n >> g >> b;
}

void process()
{
    if(g >= b)
    {
        cout << n << endl; return;
    }
    ll routine = n / (g+g);
    if(n%(g+g) == 0) routine--;
    n -= routine*(g+g);
    ll sum = routine * (g+b);
    ll unused = routine * (b-g);
    ll bad = n/2, good = n-bad;
    sum += good;
    bad -= unused;
    if(bad > 0) sum += bad;
    cout << sum << endl;
}

