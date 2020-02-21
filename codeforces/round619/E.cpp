// by redleaf23477
// RMQ using 2d seg tree, TLE
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

const int N = 501;
const int LG_N = 9;

ll LG[N];

struct SparseTable1D
{
    int n;
    ll st[N][LG_N+1];
    void buildst(int _n, ll *arr)
    {
        n = _n;
        for(int i = 0; i < n; i++)
            st[i][0] = arr[i];
        for(int lg = 0; lg < LG_N; lg++)
            for(int i = 0; i < n; i++)
            {
                st[i][lg+1] = st[i][lg];
                if(i+(1<<lg) < n)
                    st[i][lg+1] = max(st[i][lg], st[i+(1<<lg)][lg]);
            }
    }
    ll query(int l, int r)
    {
        ll lg = LG[r-l+1];
        /*
        cout << "query 1D on " << var(l) << var(r) << ", ";
        cout << var(lg) << endl; cout.flush();
        */
        return max(st[l][lg], 
                st[r-(1<<lg)+1][lg]);
    }
    void merge(SparseTable1D &a, SparseTable1D &b)
    {
        n = a.n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= LG_N; j++)
                st[i][j] = max(a.st[i][j], b.st[i][j]);
    }
    void print()
    {
        cout << var(n) << endl;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= LG_N; j++)
                cout << st[i][j] << " \n"[j==LG_N];
    }
};

struct SparseTable2D
{
    int n;
    SparseTable1D st[N][LG_N+1];
    void buildst(int _n, int _m, ll (*arr)[N])
    {
        n = _n;
        for(int i = 0; i < n; i++)
            st[i][0].buildst(_m, arr[i]);
        for(int lg = 0; lg < LG_N; lg++)
            for(int i = 0; i < n; i++)
            {
                if(i+(1<<lg) < n)
                {
                    st[i][lg+1].merge(st[i][lg], st[i+(1<<lg)][lg]);
                }
                else
                {
                    st[i][lg+1] = st[i][lg];
                }
            }
    }
    ll query(int l1, int r1, int l2, int r2)
    {
        ll lg = LG[r1-l1+1];
        return max(st[l1][lg].query(l2, r2), st[r1-(1<<lg)+1][lg].query(l2, r2));
    }
};

ll R, C, Q;
char arr[N][N];
ll logo[N][N];
SparseTable2D st;

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
    // build LG
    LG[1] = 0;
    for(int i = 2; i < N; i++)
        LG[i] = LG[i/2]+1;
    // find all logo
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            logo[r][c] = getLogoSize(r, c);
    /*
    cout << "found logos" << endl;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cout << logo[r][c] << " \n"[c==C-1];
    */
    // build 2d sparse table
    st.buildst(R, C, logo);
    /*
    cout << "SparseTable 1D" << endl;
    for(int r = 0; r < R; r++)
    {
        for(int len = 0; len <= LG_N; len++)
            cout << st.st[r][1].st[0][len] << " ";
        cout << endl;
    }
    */
}

void process()
{
    ll r1, c1, r2, c2;
    while(Q--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        ll low = 1, high = min(r2-r1+1, c2-c1+1)/2, mid, ans = 0;
        while(low <= high)
        {
            mid = (low+high)/2;
//            cout << var(mid) << var(r1+mid-1) << var(r2-mid) << var(c1+mid-1) << var(c2-mid) << endl; cout.flush();
            if(r1+mid-1 <= r2-mid && c1+mid-1 <= c2-mid &&
                    st.query(r1+mid-1, r2-mid, c1+mid-1, c2-mid) >= mid) ans = mid, low = mid+1;
            else high = mid-1;
        }
        cout << 4*ans*ans << endl;
    }
}

