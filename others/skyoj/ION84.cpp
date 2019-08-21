//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const ll INF = 1ll<<60;

struct Node
{
    ll mxIdx, mxVal;
    ll mnIdx, mnVal;
    void setMax(ll idx, ll val) { mxIdx = idx, mxVal = val; }
    void setMin(ll idx, ll val) { mnIdx = idx, mnVal = val; }
};

class Seg1D
{
private:
    static const int N = 5050*4;
    Node st[N];
    void up(Node &p, Node &lson, Node &rson)
    {
        if(lson.mxVal > rson.mxVal) p.setMax(lson.mxIdx, lson.mxVal);
        else p.setMax(rson.mxIdx, rson.mxVal);
        if(lson.mnVal < rson.mnVal) p.setMin(lson.mnIdx, lson.mnVal);
        else p.setMin(rson.mnIdx, rson.mnVal);
    }

public:
    void build(int l, int r, int idx, ll *arr)
    {
        if(l == r)
        {
            st[idx].setMax(l, arr[l]);
            st[idx].setMin(l, arr[l]);
            return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(st[idx], st[lson], st[rson]);
    }
    tuple<ll, ll> queryMax(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return make_tuple(-INF, -1);
        if(L <= l && r <= R) return make_tuple(st[idx].mxVal, st[idx].mxIdx);
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        tuple<ll, ll> lres, rres;
        lres = queryMax(l, mid, lson, L, R);
        rres = queryMax(mid+1, r, rson, L, R);
        return max(lres, rres);
    }
    tuple<ll, ll> queryMin(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return make_tuple(INF, -1);
        if(L <= l && r <= R) return make_tuple(st[idx].mnVal, st[idx].mnIdx);
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        tuple<ll, ll> lres, rres;
        lres = queryMin(l, mid, lson, L, R);
        rres = queryMin(mid+1, r, rson, L, R);
        return min(lres, rres);
    }
};

const int N = 5050;

int n, q;
ll arr[N];
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
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    st.build(0, n-1, 1, arr);
}

void process()
{
    while(q--)
    {
        int l, r; cin >> l >> r; l--, r--;
        ll mxIdx, mnIdx;
        tie(ignore, mxIdx) = st.queryMax(0, n-1, 1, l, r);
        tie(ignore, mnIdx) = st.queryMin(0, n-1, 1, l, r);
        cout << abs(mxIdx - mnIdx) << endl;
    }
}

