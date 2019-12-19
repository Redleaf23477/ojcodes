#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using Mat = vector<vector<ll>>;
#define endl '\n'

const int N = 100005;
const ll MOD = 1e9+7;

struct Mat
{
    ll arr[2][2];
    Mat() { memset(arr, 0, sizeof(arr)); }
    ll *operator[] (int idx) { return arr[idx]; }
};

Mat I2;  // [[1,0][0,1]]

inline void add_self(ll &lhs, ll rhs)
{
    lhs += rhs;
    if(lhs >= MOD) lhs -= MOD;
}

inline Mat multiply(Mat lhs, Mat rhs)
{
    Mat res;
    //res.resize(2); for(auto &r : res) r.resize(2, 0);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
            {
//                add_self(res[i][j], lhs[i][k]*rhs[k][j]%MOD);
                res[i][j] = (res[i][j] + lhs[i][k]*rhs[k][j])%MOD;
            }
    return res;
}

struct Node
{
    bool isRev;
    Mat mul;
    Node()
    {
    }
};

int n, q;
string arr;
//Node st[4*N];
Mat mul[4*N];
bool isRev[4*N];

void build(int l, int r, int idx)
{
    isRev[idx] = false;
    //mul[idx].resize(2); for(auto &rr:mul[idx]) rr.resize(2, 0);
    if(l == r)
    {
        if(arr[l] == 'A')
        {
            mul[idx][0][0] = 1, mul[idx][0][1] = 1;
            mul[idx][1][0] = 0, mul[idx][1][1] = 1;
        }
        else
        {
            mul[idx][0][0] = 1, mul[idx][0][1] = 0;
            mul[idx][1][0] = 1, mul[idx][1][1] = 1;
        }
        return;
    }
    int mid = (l+r)>>1, lson = idx<<1, rson = lson|1;
    build(l, mid, lson);
    build(mid+1, r, rson);
    mul[idx] = multiply(mul[lson], mul[rson]);
}

inline void toggle(Mat &c)  
{
    swap(c[0][0], c[0][1]);
    swap(c[1][0], c[1][1]);
    swap(c[0][0], c[1][0]);
    swap(c[0][1], c[1][1]);
}

inline void down(int idx)
{
    if(isRev[idx] == false) return;
    // isRev[idx] == true
    int lson = idx<<1, rson = lson|1;
    if(lson < 4*N)
    {
        isRev[lson] = !isRev[lson];
        toggle(mul[lson]);
    }
    if(rson < 4*N)
    {
        isRev[rson] = !isRev[rson];
        toggle(mul[rson]);
    }
    isRev[idx] = false;
}

void addTag(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return;
    if(L <= l && r <= R)
    {
        isRev[idx] = !isRev[idx];
        toggle(mul[idx]);
        return;
    }
    int mid = (l+r)>>1, lson = idx<<1, rson = lson|1;
    down(idx);
    addTag(l, mid, lson, L, R);
    addTag(mid+1, r, rson, L, R);
    mul[idx] = multiply(mul[lson], mul[rson]);
}

Mat query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return I2;
    if(L <= l && r <= R)
    {
        return mul[idx];
    }
    down(idx);
    int mid = (l+r)>>1, lson = idx<<1, rson = lson|1;
    return multiply(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
}

inline void init()
{
    //I2 init
    I2[0][0] = I2[1][1] = 1;
    /*
    I2.resize(2);
    for(int i = 0; i < 2; i++)
    {
        I2[i].resize(2, 0);
        I2[i][i] = 1;
    }
    */
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
            cout << (A*res[0][0]+B*res[0][1])%MOD << " " << (A*res[1][0]+B*res[1][1])%MOD << endl;
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

