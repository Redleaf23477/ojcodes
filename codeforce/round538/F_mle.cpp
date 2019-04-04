// stuck on MLE
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int primeNum = 62;
const ll MOD = 1e9+7;
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

vector<ll> factorize(ll x)
{
    vector<ll> res(primeNum, 0);
    for(int i = 0; i < primeNum; i++)
    {
        while(x%primes[i] == 0) res[i]++, x/=primes[i];
    }
    return res;
}

ll fpw(ll a, ll p)
{
    if(p == 0) return 1;
    if(p%2 == 0) return fpw(a*a%MOD, p/2);
    else return fpw(a*a%MOD, p/2)*a%MOD;
}

/////////////////////

struct Node
{
    vector<ll> fac, tag;
    Node()
    {
        fac.resize(primeNum, 0);
        tag.resize(primeNum, 0);
    }
};

void vec_add(vector<ll> &res, vector<ll> &lhs, vector<ll> &rhs)
{
    for(int i = 0; i < primeNum; i++) res[i] = lhs[i]+rhs[i];
}

/////////////////////

const int N = 400005;
int n, q, arr[N];
Node st[4*N];

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

void up(int idx, int lson, int rson)
{
    vec_add(st[idx].fac, st[lson].fac, st[rson].fac);
}

void down(int l, int r, int idx, int lson, int rson)
{
    vec_add(st[lson].tag, st[idx].tag, st[lson].tag);
    vec_add(st[rson].tag, st[idx].tag, st[rson].tag);
    int segLen = r-l+1;
    for(int i = 0; i < primeNum; i++) 
    {
        st[idx].fac[i] += segLen * st[idx].tag[i];
        st[idx].tag[i] = 0;
    }
}

void build_st(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx].fac = factorize(arr[l]);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    build_st(l, mid, lson);
    build_st(mid+1, r, rson);
    up(idx, lson, rson);
}

void modify(int l, int r, int idx, int L, int R, vector<ll> &fac)
{
    if(r < L || R < l) return;
    if(L <= l && r <= R)
    {
        vec_add(st[idx].tag, st[idx].tag, fac);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    down(l, r, idx, lson, rson);
    modify(l, mid, lson, L, R, fac);
    modify(mid+1, r, rson, L, R, fac);
    up(idx, lson, rson);
}

vector<ll> query(int l, int r, int idx, int L, int R)
{
    vector<ll> res(primeNum, 0);
    if(r < L || R < l) return res;
    down(l, r, idx, L, R);
    if(L <= l && r <= R)
    {
        return st[idx].fac;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    vector<ll> lqry = query(l, mid, lson, L, R);
    vector<ll> rqry = query(mid+1, r, rson, L, R);
    vec_add(res, lqry, rqry);
    return res;
}

ll calc(vector<ll> fac)
{
    /*
    for(int i = 0; i < primeNum; i++) cout << fac[i] << " ";
    cout << endl;
    return 7122;
    */
    ll res = 1;
    for(int i = 0; i < primeNum; i++)
    {
        if(fac[i] == 0) continue;
        res = res * (primes[i]-1) * fpw(primes[i], fac[i]-1) % MOD;
    }
    return res;
}

void init()
{
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build_st(0, n-1, 1);
}


void process()
{
    string cmd;
    while(q--)
    {
        cin >> cmd;
        if(cmd[0] == 'M')
        {
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            vector<ll> facx = factorize(x);
            modify(0, n-1, 1, l, r, facx);
        }
        else
        {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << calc(query(0, n-1, 1, l, r)) << endl;
        }
    }
}


/*
void pre()
{
    // get prime leq 300
    vector<bool> isPrime(301, true);
    for(int i = 2; i <= 300; i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i*i; j <= 300; j+=i) isPrime[j] = false;
        }
    }
    primeNum = primes.size();
    cout << primeNum << endl;
    for(auto p:primes) cout << p << ", ";
    cout << endl;
}
*/
