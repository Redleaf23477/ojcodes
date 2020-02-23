// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

const int N = 501;
const int LG_N = 9;

struct SparseTable1D
{
    int n;
    ll LG[N];
    ll st[N][LG_N+1];
    void buildLG()
    {
        LG[1] = 0;
        for(int i = 2; i <= n; i++)
            LG[i] = LG[i/2]+1;
    }
    void buildst(int _n, ll *arr)
    {
        n = _n;
        buildLG();
        for(int i = 0; i < n; i++)
            st[i][0] = arr[i];
        for(int lg = 0; lg < LG_N; lg++)
            for(int i = 0; i < n; i++)
            {
                st[i][lg+1] = st[i][lg];
                if(i+(1<<lg) < n)
                    st[i][lg+1] = max(st[i][lg], st[i+(1<<lg)][lg]);
            }
        for(int i = 0; i < n; i++)
            for(int lg = 0; lg <= LG_N; lg++)
                cout << st[i][lg] << " \n"[lg==LG_N];
    }
    ll query(int l, int r)
    {
        ll lg = LG[r-l+1];
        return max(st[l][lg], st[r-(1<<lg)+1][lg]);
    }
};

int n;
ll arr[N];
SparseTable1D st;

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
    st.buildst(n, arr);
}

void process()
{
    int l, r;
    while(cin >> l >> r)
    {
        cout << st.query(l, r) << endl;
    }
}

