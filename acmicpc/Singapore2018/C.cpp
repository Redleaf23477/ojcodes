//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll h0, h1, h2;
string s1, s2;
ll t1, t2;
ll v1, v2;
const ll MOD = 1e9+7;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> h0;
    h1 = 710000000, h2 = 220000000;
    s1 = "jinkela", s2 = "jizz";
}

bool test()
{
    ll v = h0;
    for(size_t i = 0; i < s1.size(); i++)
    {
        v = (v*31 + s1[i])%MOD;
    }
    ll h = (v*7+t1)%MOD;
    if(h%10000000 != 0) return false;
    v = h;
    for(size_t i = 0; i < s2.size(); i++)
    {
        v = (v*31 + s2[i])%MOD;
    }
    h = (v*7+t2)%MOD;
    if(h%10000000 != 0) return false;
    return true;
}

void process()
{
    v1 = h0;
    for(size_t i = 0; i < s1.size(); i++)
    {
        v1 = (v1*31 + s1[i])%MOD;
    }
    t1 = (h1-v1*7)%MOD; if(t1 < 0) t1 += MOD;

    v2 = h1;
    for(size_t i = 0; i < s2.size(); i++)
    {
        v2 = (v2*31 + s2[i])%MOD;
    }
    t2 = (h2-v2*7)%MOD; if(t2 < 0) t2 += MOD;

    cout << s1 << " " << t1 << endl;
    cout << s2 << " " << t2 << endl;

    if(test() == false) cout << "WA" << endl;
}

