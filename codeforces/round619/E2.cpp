// by redleaf23477
// RMQ using 2d seg tree, TLE
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
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

ll R, C, Q;
char arr[N][N];
ll logo[N][N];
Seg2D st;

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

inline bool isLegal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

inline bool checkColor(int r, int c, int dr, int dc, int len, char color)
{
    for(int i = 0; i < len; i++)
        if(!isLegal(r+i*dr, c+i*dc) || arr[r+i*dr][c+i*dc] != color)
            return false;
    return true;
}

ll getLogoSize(int r, int c)
{
    for(ll len = 1; len < R; len++)
    {
        bool good = true;
        
        // red
        good &= checkColor(r-len+1, c-len+1, 0, 1, len, 'R');
        good &= checkColor(r-len+1, c-len+1, 1, 0, len, 'R');
        // green 
        good &= checkColor(r-len+1, c+1, 0, 1, len, 'G');
        good &= checkColor(r-len+1, c+1, 1, 0, len, 'G');
        // yellow 
        good &= checkColor(r+1, c-len+1, 0, 1, len, 'Y');
        good &= checkColor(r+1, c-len+1, 1, 0, len, 'Y');
        // blue
        good &= checkColor(r+1, c+1, 0, 1, len, 'B');
        good &= checkColor(r+1, c+1, 1, 0, len, 'B');
        
        if(good == false) return len-1;
    }
    // unreachable
    return -1;
}

void init()
{
    cin >> R >> C >> Q;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> arr[r][c];
    // find all logo
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            logo[r][c] = getLogoSize(r, c);
    cout << "found logos" << endl;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cout << logo[r][c] << " \n"[c==C-1];
    // build 2d segment tree
    st.buildst(0, R-1, 0, C-1, 1, logo);
}

void process()
{
    ll l1, r1, l2, r2;
    while(Q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        l1--, r1--, l2--, r2--;
        ll low = 0, high = R, mid, ans = 0;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(l1+mid-1 <= l2-mid && r1+mid-1 <= r2-mid && 
                st.query(0, R-1, 0, C-1, 1, l1+mid-1, l2-mid, r1+mid-1, r2-mid) >= mid) ans = mid, low = mid+1;
            else high = mid-1;
        }
        cout << 4*ans*ans << endl;
    }
}

