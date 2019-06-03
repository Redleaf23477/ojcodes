//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

ll sp[1000006];
map<ll, ll> cal;
vector<ll> primes;

ll a, b;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int caseN = 0;
    while(cin >> a >> b)
    {
        cout << "case " << ++caseN << ": ";
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    for(int i = 0; i <= 1000000; i++) sp[i] = i;
    for(ll i = 2; i*i <= 1000000; i++)
    {
        if(sp[i] == i)
        {
            primes.push_back(i);
            for(ll j = i*i; j <= 1000000; j += i)
                if(sp[j] == j) sp[j] = i;
        }
    }
}

ll fpw(ll a, ll x)
{
    if(x == 0) return 1;
    if(x%2 == 1) return a*fpw(a*a, x/2);
    else return fpw(a*a, x/2);
}

ll run(ll x)
{
    if(cal.count(x) != 0) return cal[x];
    ll bk = x;
    map<ll, ll> mp;
    int i = 0;
    while(x > 1000000)
    {
        if(x%primes[i] == 0) 
        {
            if(mp.count(primes[i]) == 0) mp[primes[i]] = 0;
            mp[primes[i]]++;
            x /= primes[i];
        }
        else i++;
    }
    while(x > 1)
    {
        if(mp.count(sp[x]) == 0) mp[sp[x]] = 0;
        mp[sp[x]]++;
        x /= sp[x];
    }
    ll res = 1;
    for(auto p:mp)
    {
        res *= (fpw(p.first, p.second+1)-1)/(p.first-1);
    }
    return cal[bk] = res;
}

void process()
{
    if(run(a)*b == run(b)*a) cout << "Yes" << endl;
    else cout << "No" << endl;
}

