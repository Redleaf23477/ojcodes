// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const ll MOD = 998244353;

ll n, m;
vector<ll> inv;

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

ll fastpw(ll x, ll p)
{
    if(p == 0) return 1;
    else if(p%2 == 0) return fastpw(x*x%MOD, p/2);
    else return x * fastpw(x*x%MOD, p/2) % MOD;
}

ll modInv(ll x) 
{
    return fastpw(x, MOD-2);
}

void init()
{
    cin >> n >> m;
    inv.resize(m+1);
    for(ll i = 0; i <= m; i++) inv[i] = modInv(i);
}

ll c(ll a, ll b)
{
    ll ans = 1;
    for(ll up = a; up >= a-b+1; up--) 
    {
        ans = ans * up % MOD;
    }
    for(ll down = 1; down <= b; down++) ans = ans * inv[down] % MOD;
    return ans;
}

ll cal(ll a)
{
    ll cc = c(a, 0);
    cc = cc % MOD;
    ll sum = cc;
    for(ll x = 1; x <= a; x++)
    {
        cc = cc * inv[x] % MOD * (a-x+1) % MOD;
        sum = (sum + cc) % MOD;
    }
    return sum * inv[2] % MOD;
}

void process()
{
    ll p1 = c(m, n-1);
//    cerr << var(p1) << endl;
    ll p2 = cal(n-2);
//    cerr << var(p2) << endl;
    ll p3 = n-2;
//    cerr << var(p3) << endl;
    cout << p1 * p2 % MOD * p3 % MOD << endl;
}

