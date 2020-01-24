//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int M = 1000006;
ll sp[M];
vector<ll> primes;

ll n;

void init();
void process();

void buildPrime()
{
    for(int i = 0; i < M; i++) sp[i] = i;
    for(ll x = 2; x < M; x++)
    {
        if(sp[x] == x)
        {
            primes.push_back(x);
            for(ll y = x*x; y < M; y += x)
                sp[y] = x;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    buildPrime();
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
}

ll breakDown(ll x)
{
    if(x < M) 
    {
        return sp[x];
    }
    else
    {
        for(auto p : primes)
        {
            if(x % p == 0) return p;
        }
        return x;
    }
}

bool makeDistinct(ll a, ll b, ll c)
{
    if(a != b && b != c && a != c)
    {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
        return true;
    }
    map<ll,ll> bk;
    vector<ll> tmp = {a, b, c};
    for(auto t : tmp)
    {
        while(t > 1)
        {
            ll x = breakDown(t);
            bk[x]++;
            t /= x;
        }
    }
    a = 1, b = 1, c = 1;
    if(bk.size() >= 3)
    {
        auto it = bk.begin();
        for(int i = 0; i < it->second; i++) a *= it->first;
        it++;
        for(int i = 0; i < it->second; i++) b *= it->first;
        it++;
        for(; it != bk.end(); it++)
            for(int i = 0; i < it->second; i++) c *= it->first;
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
        return true;
    }
    else if(bk.size() == 2)
    {
        auto it = bk.begin();
        ll x1 = it->first, y1 = it->second;
        it++;
        ll x2 = it->first, y2 = it->second;
        if(y1 + y2 == 3) return false;
        a *= x1, y1--;
        b *= x2, y2--;
        while(y1--) c *= x1;
        while(y2--) c *= x2;
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
        return true;
    }
    else if(bk.size() == 1)
    {
        auto it = bk.begin();
        ll x1 = it->first, y1 = it->second;
        if(y1 < 6) return false;
        a = x1, y1--;
        b = x1 * x1, y1 -= 2;
        while(y1--) c *= x1;
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
        return true;
    }
    return false;
}

void process()
{
    bool good = false;
    for(ll a = 2; a*a <= n && !good; a++)
    {
        if(n%a != 0) continue;
        ll tmp = n/a;
        if(tmp < M)
        {
            if(sp[tmp] != tmp) good = makeDistinct(a, sp[tmp], tmp/sp[tmp]);
        }
        else
        {
            for(auto p : primes)
            {
                if(tmp % p == 0) good = makeDistinct(a, p, tmp/p);
                if(good) break;
            }
        }
    }
    if(good == false) cout << "NO" << endl;
}

