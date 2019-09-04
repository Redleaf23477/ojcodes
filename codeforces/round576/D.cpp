//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

/*
 * 1D Segment Tree
 *
 * Tested using : https://atcoder.jp/contests/dp/tasks/dp_q
 *
 * Function : range query, single entry modify
 * Time Complexity:
 * build : O(n)
 * query : O(lg n)
 * modify : O(lg n)
 */

using ll = long long;

struct Node
{
    ll val, tag;
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
        if(p.tag >= 0)
        {
            lson.tag = max(lson.tag, p.tag);
            rson.tag = max(rson.tag, p.tag);
        }
        p.tag = -1;
    }
    void _build(int l, int r, int idx, ll *arr)
    {
        st[idx].tag = -1;
        if(l == r) 
        {
            st[idx].val = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = lson+1;
        _build(l, mid, lson, arr);
        _build(mid+1, r, rson, arr);
    }
    ll _query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return -INF;
        if(L <= l && r <= R) return max(st[idx].val, st[idx].tag);
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        _down(st[idx], st[lson], st[rson]);
        return max(_query(l, mid, lson, L, R), _query(mid+1, r, rson, L, R));
    }
    void _modify(int l, int r, int idx, int pos, ll val)
    {
        if(pos < l || r < pos) return;
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        if(l != r) _down(st[idx], st[lson], st[rson]);
        if(l == pos && r == pos) { st[idx].val = val; st[idx].tag = -1; return; }
        _modify(l, mid, lson, pos, val);
        _modify(mid+1, r, rson, pos, val);
    }
    void _modify(int l, int r, int idx, int L, int R, ll tag)
    {
        if(r < L || R < l) return;
        if(L <= l && r <= R) { st[idx].tag = max(st[idx].tag, tag); return; }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        _down(st[idx], st[lson], st[rson]);
        _modify(l, mid, lson, L, R, tag);
        _modify(mid+1, r, rson, L, R, tag);
    }
public:
    void build(int n) { _n = n; }
    void build(ll *arr, int n) { _n = n, _build(0, n-1, 1, arr); }
    ll query(int l, int r) { return _query(0, _n-1, 1, l, r); }
    void modify(int pos, ll val) { _modify(0, _n-1, 1, pos, val); }
    void modify(int l, int r, ll val) { _modify(0, _n-1, 1, l, r, val); }
};

const int N = 200005;

int n, q;
ll arr[N];
Seg1D seg;

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
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> q;
    seg.build(arr, n);
}

void process()
{
    while(q--)
    {
        int cmd, p, x;
        cin >> cmd;
        if(cmd == 1)
        {
            cin >> p >> x;
            seg.modify(p-1, x);
        }
        else
        {
            cin >> x;
            seg.modify(0, n-1, x);
        }
    }
    for(int i = 0; i < n; i++)
        cout << seg.query(i, i) << " ";
    cout << endl;
}

