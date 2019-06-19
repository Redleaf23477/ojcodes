//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define pk first
#define mask second

const int N = 400005, M = 303;
const ll MOD = 1e9+7;

struct Node
{
    P tag, val;
    ll tagExtPk;
    ll segLen;
};

// up for segment tree
P operator + (const P &lhs, const P &rhs)
{
    return make_pair(lhs.pk*rhs.pk%MOD, lhs.mask|rhs.mask);
}

vector<int> primes, inv;
P preTable[M];
Node st[4*N];

int n, q;
int arr[N];

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

P factorize(ll x)
{
    ll mask = 0, pk = x;
    for(size_t i = 0; i < primes.size(); i++)
    {
        while(x % primes[i] == 0) mask |= (1ll<<i), x /= primes[i];
    }
    return make_pair(pk, mask);
}

ll fastPw(ll a, ll p)
{
    if(p == 0) return 1;
    if(p%2 == 0) return fastPw(a*a%MOD, p/2);
    else return a*fastPw(a*a%MOD, p/2)%MOD;
}

ll modInv(ll x)
{
    return fastPw(x, MOD-2);
}

void buildst(int l, int r, int idx)
{
    st[idx].segLen = r-l+1;
    st[idx].tagExtPk = 1;
    st[idx].tag = make_pair(1, 0);
    if(l == r)
    {
        st[idx].val = preTable[arr[l]];
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    buildst(l, mid, lson);
    buildst(mid+1, r, rson);
    st[idx].val = st[lson].val + st[rson].val;
}

void down(int idx, int lson, int rson)
{
    st[idx].val.pk = st[idx].val.pk * st[idx].tagExtPk % MOD;
    st[idx].val.mask |= st[idx].tag.mask;

    st[lson].tag = st[idx].tag + st[lson].tag;
    st[lson].tagExtPk = fastPw(st[lson].tag.pk, st[lson].segLen);
    st[rson].tag = st[idx].tag + st[rson].tag;
    st[rson].tagExtPk = fastPw(st[rson].tag.pk, st[rson].segLen);

    st[idx].tagExtPk = 1;
    st[idx].tag = make_pair(1, 0);
}

void up(int idx, int lson, int rson)
{
    ll lmask = st[lson].tag.mask | st[lson].val.mask;
    ll rmask = st[rson].tag.mask | st[rson].val.mask;
    ll lpk = st[lson].val.pk * st[lson].tagExtPk % MOD;
    ll rpk = st[rson].val.pk * st[rson].tagExtPk % MOD;
    
    st[idx].val.mask = lmask | rmask;
    st[idx].val.pk = lpk * rpk % MOD;
}

void modify(int l, int r, int idx, int L, int R, int val)
{
    if(r < L || R < l) return;
    if(L <= l && r <= R)
    {
        st[idx].tag = st[idx].tag + preTable[val];
        st[idx].tagExtPk = fastPw(st[idx].tag.pk, st[idx].segLen);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    down(idx, lson, rson);
    modify(l, mid, lson, L, R, val);
    modify(mid+1, r, rson, L, R, val);
    up(idx, lson, rson);
}

P query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return P(1, 0);
    if(L <= l && r <= R)
    {
        ll pk = st[idx].val.pk * st[idx].tagExtPk % MOD;
        ll mask = st[idx].val.mask | st[idx].tag.mask;
        return make_pair(pk, mask);
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    down(idx, lson, rson);
    P left = query(l, mid, lson, L, R);
    P right = query(mid+1, r, rson, L, R);
    return left + right;
}

void init()
{
    // build prime table
    for(int i = 2; i <= 300; i++)
    {
        bool isPrime = true;
        for(int j = 2; j < i && isPrime; j++)
        {
            if(i%j == 0) isPrime = false;
        }
        if(isPrime) primes.push_back(i), inv.push_back(modInv(i));
    }

    // pre-calculate pk and mask for each number between 1~300
    for(int x = 1; x <= 300; x++)
    {
        preTable[x] = factorize(x);
    }

    // input and build st
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    buildst(0, n-1, 1);
}

void process()
{
    string cmd;
    int l, r, v;
    while(q--)
    {
        cin >> cmd >> l >> r; l--, r--;
        if(cmd[0] == 'M')
        {
            cin >> v;
            modify(0, n-1, 1, l, r, v);
        }
        else
        {
            P res = query(0, n-1, 1, l, r);
            ll ans = res.pk;
            for(int i = 0; i < 64; i++)
            {
//                if((res.mask>>i)&1) ans = ans * ((1-modInv(primes[i])+MOD)%MOD) % MOD;
                if((res.mask>>i)&1) ans = ans * (primes[i]-1) % MOD * inv[i] % MOD;
            }

            cout << ans << endl;
        }
    }
}

