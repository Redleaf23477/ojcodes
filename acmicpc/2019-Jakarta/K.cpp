#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Mat = vector<vector<ll>>;
#define endl '\n'

const int N = 100005;
const ll MOD = 1e9+7;

Mat I2;  // [[1,0][0,1]]

inline void add_self(ll &lhs, ll rhs)
{
    lhs += rhs;
    if(lhs >= MOD) lhs -= MOD;
}

inline Mat mul(Mat lhs, Mat rhs)
{
    Mat res;
    res.resize(lhs.size()); for(auto &r : res) r.resize(rhs[0].size(), 0);
    for(size_t i = 0; i < lhs.size(); i++)
        for(size_t j = 0; j < rhs[0].size(); j++)
            for(size_t k = 0; k < rhs.size(); k++)
            {
                add_self(res[i][j], lhs[i][k]*rhs[k][j]%MOD);
            }
    return res;
}

struct Node
{
    bool isRev;
    Mat mul, rev;
    Node()
    {
    }
};

int n, q;
string arr;
Node st[4*N];

void build(int l, int r, int idx)
{
    st[idx].isRev = false;
    st[idx].mul.resize(2); for(auto &rr:st[idx].mul) rr.resize(2, 0);
    st[idx].rev.resize(2); for(auto &rr:st[idx].rev) rr.resize(2, 0);
    if(l == r)
    {
        if(arr[l] == 'A')
        {
            st[idx].mul[0][0] = 1, st[idx].mul[0][1] = 1;
            st[idx].mul[1][0] = 0, st[idx].mul[1][1] = 1;
            st[idx].rev[0][0] = 1, st[idx].rev[0][1] = 0;
            st[idx].rev[1][0] = 1, st[idx].rev[1][1] = 1;
        }
        else
        {
            st[idx].mul[0][0] = 1, st[idx].mul[0][1] = 0;
            st[idx].mul[1][0] = 1, st[idx].mul[1][1] = 1;
            st[idx].rev[0][0] = 1, st[idx].rev[0][1] = 1;
            st[idx].rev[1][0] = 0, st[idx].rev[1][1] = 1;
        }
        return;
    }
    int mid = (l+r)>>1, lson = idx<<1, rson = lson|1;
    build(l, mid, lson);
    build(mid+1, r, rson);
    st[idx].mul = mul(st[lson].mul, st[rson].mul);
    st[idx].rev = mul(st[lson].rev, st[rson].rev);
}

inline Mat getCorrectMat(int idx, bool getRev = false)
{
    if(st[idx].isRev) getRev = !getRev;
    if(getRev) return st[idx].rev;
    else return st[idx].mul;
}

inline void down(int idx)
{
    if(st[idx].isRev == false) return;
    // st[idx].isRev = true
    int lson = idx<<1, rson = lson|1;
    st[lson].isRev = !st[lson].isRev;
    st[rson].isRev = !st[rson].isRev;
    /*
       st[idx].mul = mul(getCorrectMat(lson), getCorrectMat(rson));
       st[idx].rev = mul(getCorrectMat(lson, true), getCorrectMat(rson, true));
       */
    swap(st[idx].mul, st[idx].rev);
    st[idx].isRev = false;
}

void addTag(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return;
    if(L <= l && r <= R)
    {
        st[idx].isRev = !st[idx].isRev; return;
    }
    int mid = (l+r)>>1, lson = idx<<1, rson = lson|1;
    down(idx);
    addTag(l, mid, lson, L, R);
    addTag(mid+1, r, rson, L, R);
    st[idx].mul = mul(getCorrectMat(lson), getCorrectMat(rson));
    st[idx].rev = mul(getCorrectMat(lson, true), getCorrectMat(rson, true));
}

Mat query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return I2;
    if(L <= l && r <= R)
    {
        return getCorrectMat(idx);
    }
    down(idx);
    int mid = (l+r)>>1, lson = idx<<1, rson = lson|1;
    return mul(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
}

inline void init()
{
    //I2 init
    I2.resize(2);
    for(int i = 0; i < 2; i++)
    {
        I2[i].resize(2, 0);
        I2[i][i] = 1;
    }
    cin >> n >> q >> arr;
    reverse(arr.begin(), arr.end());
    build(0, n-1, 1);
}

inline void process()
{
    while(q--)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int l, r; cin >> l >> r; 
            int tmpl = l, tmpr = r;
            l = 1+n-tmpr, r = 1+n-tmpl;
            l--, r--;
            addTag(0, n-1, 1, l, r);
        }
        else
        {
            int l, r; ll A, B; cin >> l >> r >> A >> B;
            int tmpl = l, tmpr = r;
            l = 1+n-tmpr, r = 1+n-tmpl;
            l--, r--;
            Mat res = query(0, n-1, 1, l, r);
            Mat AB;
            AB.resize(2); AB[0].push_back(A), AB[1].push_back(B);
            res = mul(res, AB);
            cout << res[0][0] << " " << res[1][0] << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
}

