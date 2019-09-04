//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

struct Node
{
    ll val;
    ll tag;
};

class Seg1D
{
private:
    static const int N = 200005;
    static const ll INF = 1ll<<60;
    int _n;
    Node st[N*4];
    void _down(Node &p, Node &lson, Node &rson)
    {
        p.val += p.tag;
        lson.tag += p.tag;
        rson.tag += p.tag;
        p.tag = 0;
    }
    void _up(Node &p, Node &lson, Node &rson)
    {
        assert(p.tag == 0);
        p.val = max(lson.val + lson.tag, rson.val + rson.tag);
    }
    void _build(int l, int r, int idx, ll *arr)
    {
        st[idx].tag = 0;
        if(l == r) 
        {
            st[idx].val = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = lson+1;
        _build(l, mid, lson, arr);
        _build(mid+1, r, rson, arr);
        _up(st[idx], st[lson], st[rson]);
    }
    ll _query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return -INF;
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        if(L <= l && r <= R) return st[idx].val + st[idx].tag;
        _down(st[idx], st[lson], st[rson]);
        return max(_query(l, mid, lson, L, R), _query(mid+1, r, rson, L, R));
    }
    void _modify(int l, int r, int idx, int L, int R, ll val)
    {
        if(r < L || R < l) return;
        if(L <= l && r <= R)
        {
            st[idx].tag += val; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        _down(st[idx], st[lson], st[rson]);
        _modify(l, mid, lson, L, R, val);
        _modify(mid+1, r, rson, L, R, val);
        _up(st[idx], st[lson], st[rson]);
    }
public:
    void build(int n) { _n = n; }
    void build(ll *arr, int n) { _n = n, _build(0, n-1, 1, arr); }
    ll query(int l, int r) { return _query(0, _n-1, 1, l, r); }
    void modify(int l, int r, ll val) { _modify(0, _n-1, 1, l, r, val); }
};

const int N = 200005;

struct Interval
{
    int l, r;
    ll val;
};

int n, m;
Interval arr[N];
vector<int> isStart[N], isEnd[N];
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
    cin >> n >> m;
    for(int i = 0; i < m; i++) 
    {
        cin >> arr[i].l >> arr[i].r >> arr[i].val;
        isStart[arr[i].l].emplace_back(i);
        isEnd[arr[i].r].emplace_back(i);
    }
    st.build(n+1);
}

void process()
{
    for(int i = 1; i <= n; i++)
    {
        for(auto idx : isStart[i])
        {
            const auto &interval = arr[idx];
            st.modify(0, interval.l-1, interval.val);
        }
        ll dpi = st.query(0, i-1);
        st.modify(i, i, dpi);
        for(auto idx : isEnd[i])
        {
            const auto &interval = arr[idx];
            st.modify(0, interval.l-1, -interval.val);
        }
    }
    cout << st.query(0, n) << endl;
}
