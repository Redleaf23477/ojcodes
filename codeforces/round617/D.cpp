// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
ll a, b, k;
vector<ll> monster;

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
    cin >> n >> a >> b >> k;
    monster.resize(n);
    for(auto &m : monster) cin >> m;
}

void process()
{
    for(auto &m : monster)
    {
        if(m%(a+b) != 0) m %= a+b;
        else if(m >= a+b) m = a+b;
        if(m <= a) m = 0;
        else
        {
            m -= a;
            m = m/a + (m%a != 0);
        }
    }
    sort(monster.begin(), monster.end());
    ll ans = 0;
    for(auto m : monster)
    {
        if(k >= m) ans++, k -= m;
        else break;
    }
    cout << ans << endl;
}

