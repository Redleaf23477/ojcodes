//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const ll INF = 1ll << 60;

struct P
{
    ll mx, mn;
    bool safe;
    P(ll a=-INF, ll b=INF, bool c=false):mx(a), mn(b), safe(c){};
};

P operator + (P lhs, P rhs)
{
    bool safe = lhs.safe && rhs.safe && lhs.mx <= 2*rhs.mn;
    return P(max(lhs.mx, rhs.mx), min(lhs.mn, rhs.mn), safe);
}

///////////////


const int N = 100005;
int n;
ll arr[3*N];  // 1~n
P st[3*4*N];  // 0~n, 0 for cyclic

void build(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx] = P(arr[l], arr[l], true);
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = lson+1;
    build(l, mid, lson);
    build(mid+1, r, rson);
    st[idx] = st[lson] + st[rson];
}

void modify(int l, int r, int idx, int pos, P v)
{
    if(pos < l || r < pos) return;
    if(pos == l && r == pos) 
    {
        st[idx] = v;
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = lson+1;
    build(l, mid, lson);
    build(mid+1, r, rson);
    st[idx] = st[lson] + st[rson];
}

P query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return P(-INF, INF, true);
    if(L <= l && r <= R) return st[idx];
    int mid = (l+r)/2, lson = idx*2, rson = lson+1;
    return query(l, mid, lson, L, R) + query(mid+1, r, rson, L, R);
}

/////////////////////


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
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
        arr[i+n] = arr[i];
        arr[i+n+n] = arr[i];
    }
    build(0, 3*n, 1);
}

bool good(int l, int r)
{
    P qry = query(0, 3*n, 1, l, r);
    return qry.safe;
}

int bs(int start)
{
    // length
    int low = 1, high = 2*n, mid, ans = 1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(good(start, start+mid-1)) ans = mid, low = mid+1;
        else high = mid-1;
    }
    return ans;
}

void process()
{
    for(int i = 1; i <= n; i++)
    {
        ll res = bs(i);
        if(res == 2*n) cout << -1 << " ";
        else cout << res << " ";
    }
    cout << endl;
}

