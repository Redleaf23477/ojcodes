//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define red first
#define blue second

const int N = 505;


struct Seg1D
{
    int st[4*N];
    void build(int l, int r, int idx);
    void up(int idx);
    void modify(int l, int r, int idx, const int pos, const int val);
    int query(int l, int r, int idx, const int L, const int R);
};

void Seg1D::build(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx] = 0; return;
    }
    int lson = idx*2, rson = idx*2+1, mid = (l+r)/2;
    build(l, mid, lson);
    build(mid+1, r, rson);
    up(idx);
}

void Seg1D::up(int idx)
{
    st[idx] = max(st[idx*2], st[idx*2+1]);
}

void Seg1D::modify(int l, int r, int idx, const int pos, const int val)
{
    if(pos < l || r < pos) return;
    if(l == pos && r == pos)
    {
        st[idx] = val; return;
    }
    int lson = idx*2, rson = idx*2+1, mid = (l+r)/2;
    modify(l, mid, lson, pos, val);
    modify(mid+1, r, rson, pos, val);
    // since the tree is all zero initially, ignore combine two subtree
}

int Seg1D::query(int l, int r, int idx, const int L, const int R)
{
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return st[idx];
    int lson = idx*2, rson = idx*2+1, mid = (l+r)/2;
    int lres = query(l, mid, lson, L, R);
    int rres = query(mid+1, r, rson, L, R);
    return max(lres, rres);
}

struct Seg2D
{
    Seg1D st[4*N];
    void build(int l1, int r1, int l2, int r2, int idx);
    void modify(int l1, int r1, int l2, int r2, int idx, const int pos1, const int pos2, const int val);
    void up(int idx2, int l1, int r1, int idx1, const int pos);
    int query(int l1, int r1, int l2, int r2, int idx, const int L1, const int R1, const int L2, const int R2);
};

void Seg2D::build(int l1, int r1, int l2, int r2, int idx)
{
    if(l2 == r2)
    {
        st[idx].build(l1, r1, 1);
        return;
    }
    int lson = idx*2, rson = idx*2+1, mid = (l2+r2)/2;
    build(l1, r1, l2, mid, lson);
    build(l1, r1, mid+1, r2, rson);
    // since the tree is all zero initially, ignore merge tree
}

void Seg2D::up(int idx2, int l1, int r1, int idx1, const int pos)
{
    if(pos < l1 || pos > r1) return;
    int lson2 = idx2*2, rson2 = idx2*2+1;
    int lson1 = idx1*2, rson1 = idx1*2+1, mid = (l1+r1)/2;
    //    st[idx2] = max(st[lson2], st[rson2]);
    if(l1 == r1)
    {
        st[idx2].st[idx1] = max(st[lson2].st[idx1], st[rson2].st[idx1]);
        return;
    }
    up(idx2, l1, mid, lson1, pos);
    up(idx2, mid+1, r1, rson1, pos);
}

void Seg2D::modify(int l1, int r1, int l2, int r2, int idx, const int pos1, const int pos2, const int val)
{
    if(pos2 < l2 || r2 < pos2) return;
    if(l2 == pos2 && r2 == pos2)
    {
        st[idx].modify(l1, r1, 1, pos1, val);
        return;
    }
    int lson = idx*2, rson = idx*2+1, mid = (l2+r2)/2;
    modify(l1, r1, l2, mid, lson, pos1, pos2, val);
    modify(l1, r1, mid+1, r2, rson, pos1, pos2, val);
    up(idx, l1, r1, 1, pos1);  //todo
}

int Seg2D::query(int l1, int r1, int l2, int r2, int idx, const int L1, const int R1, const int L2, const int R2)
{
    if(r2 < L2 || R2 < l2) return 0;
    if(L2 <= l2 && r2 <= R2)
    {
        return st[idx].query(l1, r1, 1, L1, R1);
    }
    int lson = idx*2, rson = idx*2+1, mid = (l2+r2)/2;
    int lres = query(l1, r1, l2, mid, lson, L1, R1, L2, R2);
    int rres = query(l1, r1, mid+1, r2, rson, L1, R1, L2, R2);
    return max(lres, rres);
}


//////////////////

ll R, B;

Seg2D dp;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> R >> B;
    dp.build(0, R, 0, B, 1);
}

void process()
{
    for(int i = 0; i < 10; i++)
}

