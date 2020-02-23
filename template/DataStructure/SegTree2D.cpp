/*
 * 2D Segment Tree
 *
 * Tested using : https://codeforces.com/contest/1301/problem/E
 *
 * Function : range max query, (modify not yet)
 * Time Complexity:
 * build : O(nm)
 * query : O(lg n lg m)
 * modify : (not yet)
 */

using ll = long long int;

const int N = 502;

struct Seg1D
{
    ll st[4*N];
    void buildst(int l, int r, int idx, ll *arr)
    {
        if(l == r) 
        {
            st[idx] = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        buildst(l, mid, lson, arr);
        buildst(mid+1, r, rson, arr);
        st[idx] = max(st[lson], st[rson]);
    }
    ll query(int l, int r, int idx, const int L, const int R)
    {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return st[idx];
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        ll lq = query(l, mid, lson, L, R);
        ll rq = query(mid+1, r, rson, L, R);
        return max(lq, rq);
    }
    void merge(int l, int r, int idx, const Seg1D &ltree, const Seg1D &rtree)
    {
        st[idx] = max(ltree.st[idx], rtree.st[idx]);
        if(l == r) return;
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        merge(l, mid, lson, ltree, rtree);
        merge(mid+1, r, rson, ltree, rtree);
    }
};

struct Seg2D
{
    Seg1D st[4*N];
    void buildst(int l1, int r1, int l2, int r2, int idx, ll (*arr)[N])
    {
        if(l1 == r1)
        {
            st[idx].buildst(l2, r2, 1, arr[l1]); return;
        }
        int mid = (l1+r1)/2, lson = idx*2, rson = idx*2+1;
        buildst(l1, mid, l2, r2, lson, arr);
        buildst(mid+1, r1, l2, r2, rson, arr);
        st[idx].merge(l2, r2, 1, st[lson], st[rson]);
    }
    ll query(int l1, int r1, int l2, int r2, int idx, const int L1, const int R1, const int L2, const int R2)
    {
        if(r1 < L1 || R1 < l1) return 0;
        if(L1 <= l1 && r1 <= R1) return st[idx].query(l2, r2, 1, L2, R2);
        int mid = (l1+r1)/2, lson = idx*2, rson = idx*2+1;
        ll lq = query(l1, mid, l2, r2, lson, L1, R1, L2, R2);
        ll rq = query(mid+1, r1, l2, r2, rson, L1, R1, L2, R2);
        return max(lq, rq);
    }
};
