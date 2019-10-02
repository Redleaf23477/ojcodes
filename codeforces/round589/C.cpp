//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll M = 1000006;
const ll MAX = 1000000000000000000ll; // 1e18
const ll MOD = 1000000007;

ll sp[M];
vector<ll> primes;
ll x, n;

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
    // build sp
    sp[0] = 0, sp[1] = 1;
    for(ll i = 2; i < M; i++)
    {
        if(sp[i] == 0)
        {
            primes.emplace_back(i);
            sp[i] = i;
            for(ll j = i*i; j < M; j += i) sp[j] = i;
        }
    }
    // input
    cin >> x >> n;
}

ll pw(ll p, ll k)
{
    if(k == 0) return 1;
    if(k%2 == 0) return pw(p*p%MOD, k/2);
    else return p*pw(p*p%MOD, k/2)%MOD;
}

void mul_self(ll &lhs, ll rhs)
{
    lhs *= rhs;
    lhs %= MOD;
}

void process()
{
    set<ll> prime;
    // get primes of x
    if(x >= M)
    {
        for(auto p : primes)
        {
            while(x%p == 0)
            {
                prime.insert(p);
                x /= p; 
                if(x < M) break;
            }
        }
    }
    if(x >= M) {prime.insert(x); x /= x;}
    while(x != 1)
    {
        prime.insert(sp[x]);
        x /= sp[x];
    }
    // cal ans
    ll ans = 1;
    for(auto p : prime)
    {
        ll pk = p;
        ll sum = 0;
        while(n / pk > 0)
        {
            sum += n/pk;
            if(pk <= MAX/p) pk *= p;
            else break;
        }
        mul_self(ans, pw(p, sum));
    }
    cout << ans << endl;
}

