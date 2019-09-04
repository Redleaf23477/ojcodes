//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

struct Node
{
    ll val;
};

class Seg1D
{
private:
    static const int N = 200005;
    static const ll INF = 1ll<<60;
    int _n;
    Node st[N*4];
    void _up(int idx, int lson, int rson)
    {
        st[idx].val = max(st[lson].val, st[rson].val);
    }
    void _build(int l, int r, int idx, ll *arr)
    {
        if(l == r) 
        {
            st[idx].val = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = lson+1;
        _build(l, mid, lson, arr);
        _build(mid+1, r, rson, arr);
        _up(idx, lson, rson);
    }
    ll _query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return -INF;
        if(L <= l && r <= R) return st[idx].val;
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        return max(_query(l, mid, lson, L, R), _query(mid+1, r, rson, L, R));
    }
    void _modify(int l, int r, int idx, int pos, ll val)
    {
        if(pos < l || r < pos) return;
        if(l == pos && r == pos) { st[idx].val = val; return; }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        _modify(l, mid, lson, pos, val);
        _modify(mid+1, r, rson, pos, val);
        _up(idx, lson, rson);
    }
public:
    void build(int n) { _n = n; }
    void build(ll *arr, int n) { _n = n, _build(0, n-1, 1, arr); }
    ll query(int l, int r) { return _query(0, _n-1, 1, l, r); }
    void modify(int pos, ll val) { _modify(0, _n-1, 1, pos, val); }
};

const int N = 200005;
int n;
ll h[N], a[N];
Seg1D st;

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
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    st.build(N-1);
}

void process()
{
    for(int i = 0; i < n; i++)
    {
        ll dpi = st.query(0, h[i]) + a[i];
        st.modify(h[i], dpi);
    }
    cout << st.query(0, N-1) << endl;
}

