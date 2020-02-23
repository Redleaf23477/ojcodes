using ll = long long int;

const int N = 501;
const int LG_N = 9;

ll LG[N];

void buildLG()
{
    LG[1] = 0;
    for(int i = 2; i < N; i++)
        LG[i] = LG[i/2]+1;
}

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
        return max(st[l][lg], st[r-(1<<lg)+1][lg]);
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
                if(i+(1<<lg) < n)
                    st[i][lg+1].merge(st[i][lg], st[i+(1<<lg)][lg]);
                else
                    st[i][lg+1] = st[i][lg];
    }
    ll query(int l1, int r1, int l2, int r2)
    {
        ll lg = LG[r1-l1+1];
        return max(st[l1][lg].query(l2, r2), st[r1-(1<<lg)+1][lg].query(l2, r2));
    }
};
