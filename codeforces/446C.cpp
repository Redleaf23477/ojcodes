// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using LL = long long int;

const LL MOD = (LL)1e9+9;

inline LL add(LL lhs, LL rhs) { lhs = (lhs + rhs) % MOD; return lhs < 0? lhs+MOD : lhs; }
inline LL mul(LL lhs, LL rhs) { lhs = lhs * rhs % MOD; return lhs < 0? lhs+MOD : lhs; }

/*
// square matrix
struct Mat : public vector<vector<LL>>
{
    int N;
    Mat(int _N = 0, bool id = true):vector<vector<LL>>(_N, vector<LL>(_N, 0)), N(_N)
    {
        if(id)
            for(int i = 0; i < N; i++) (*this)[i][i] = 1;
    }
    Mat operator + (Mat that)
    {
        Mat ret = *this;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++)
                ret[r][c] = add(ret[r][c], that[r][c]);
        return ret;
    }
    Mat operator * (Mat that)
    {
        Mat ret = Mat(N, false);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                    ret[i][j] = add(ret[i][j], mul((*this)[i][k], that[k][j]));
        return ret;
    }
};
*/

// 2x2 square Matrix
struct Mat
{
    static const int N = 2;
    LL m[2][2];
    Mat(bool id = true)
    {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
        if(id) m[0][0] = m[1][1] = 1;
    }
    Mat operator + (Mat that)
    {
        Mat ret = *this;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                ret.m[i][j] = (ret.m[i][j] + that.m[i][j]) % MOD;
        return ret;
    }
    Mat operator * (Mat that)
    {
        Mat ret = Mat(false);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                    ret.m[i][j] = (ret.m[i][j] + this->m[i][k] * that.m[k][j]) % MOD;
        return ret;
    }
};


Mat M, W;

Mat pow(Mat m, LL p)
{
    Mat res;
    while(p > 0)
    {
        if(p % 2 == 1) res = res * m;
        p /= 2;
        m = m * m;
    }
    return res;
}

struct Seg1D
{
    struct Node
    {
        Mat m_sum, tag;
        LL val; // sum of segment
        Node():m_sum(false), tag(false), val(0) {}
    };
    int n;
    vector<Node> st;
    Seg1D(int _n, vector<LL> &arr, vector<Mat> &pref):n(_n), st(4*(n+1))
    {
        build(1, n, 1, arr, pref);
    }
    inline LL getVal(int idx)
    {
        Mat tmp = st[idx].m_sum * st[idx].tag;
        LL tagVal = (tmp.m[0][0] + tmp.m[0][1]) % MOD;
        return (st[idx].val + tagVal) % MOD;
    }
    inline void down(int idx, int lson, int rson)
    {
        // update self
        st[idx].val = getVal(idx);
        // pass down
        st[lson].tag = st[lson].tag + st[idx].tag;
        st[rson].tag = st[rson].tag + st[idx].tag;
        // reset self
        st[idx].tag = Mat(false);
    }
    void build(int l, int r, int idx, vector<LL> &arr, vector<Mat> &m)
    {
        if(l == r)
        {
            st[idx].m_sum = m[l];
            st[idx].val = arr[l];
            return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr, m);
        build(mid+1, r, rson, arr, m);
        // up
        st[idx].m_sum = st[lson].m_sum + st[rson].m_sum;
        st[idx].val = (st[lson].val + st[rson].val) % MOD;
    }
    LL query(int L, int R) { return query(1, n, 1, L, R); }
    LL query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R)
        {
            return getVal(idx);
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        down(idx, lson, rson);
        return (query(l, mid, lson, L, R) + query(mid+1, r, rson, L, R)) % MOD;
    }
    void modify(int L, int R, int x) { modify(1, n, 1, L, R, pow(W, x)); }
    void modify(int l, int r, int idx, int L, int R, Mat x)
    {
        if(r < L || R < l) return;
        if(L <= l && r <= R)
        {
            st[idx].tag = st[idx].tag + x;
            return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        down(idx, lson, rson);
        modify(l, mid, lson, L, R, x);
        modify(mid+1, r, rson, L, R, x);
        st[idx].val = (getVal(lson) + getVal(rson)) % MOD;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    M = Mat();
    M.m[0][0] = 0, M.m[0][1] = 1;
    M.m[1][0] = 1, M.m[1][1] = 1;
    W = Mat();
    W.m[0][0] = MOD-1, W.m[0][1] = 1;
    W.m[1][0] = 1, W.m[1][1] = 0;

    int n, q; cin >> n >> q;
    vector<LL> arr(n+1); for(int i = 1; i <= n; i++) cin >> arr[i];
    vector<Mat> m(n+1, Mat()); for(int i = 2; i <= n; i++) m[i] = m[i-1] * M;
    Seg1D st(n, arr, m);
    while(q--)
    {
        int cmd, l, r; cin >> cmd >> l >> r; 
        if(cmd == 1) st.modify(l, r, l-1);
        else cout << st.query(l, r) << endl;
    }
    cout.flush();
    return 0;
}
