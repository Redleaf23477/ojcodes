// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

struct Seg1D
{
    int n;
    vector<ll> st;
    void build(int l, int r, int idx, vector<ll> &arr)
    {
        if(l == r)
        {
            st[idx] = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        st[idx] = max(st[lson], st[rson]);
    }
    ll query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return st[idx];
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        return max(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
    Seg1D(int _n, vector<ll> &arr):n(_n)
    {
        st.assign(4*n, 0);
        build(0, n-1, 1, arr);
    }
    ll query(int L, int R) { return query(0, n-1, 1, L, R); }
};

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

ll n, k;
vector<ll> pos;

void init()
{
    cin >> n >> k;
    pos.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> pos[i];
    for(int _, i = 0; i < n; i++) cin >> _;
    sort(pos.begin(), pos.end());

    /*
    cerr << "x = ";
    for(auto x : pos) cerr << x << " ";
    cerr << endl;
    */
}

void process()
{
    vector<ll> eat(n);
    for(int i = 0; i < n; i++)
    {
        int r = upper_bound(pos.begin(), pos.end(), pos[i]+k) - pos.begin();
        eat[i] = r-i;
    }
    /*
    cerr << "eat = ";
    for(auto x : eat) cerr << x << " ";
    cerr << endl;
    */

    Seg1D mx(n, eat);
    ll ans = 0;
    for(int x1 = 0; x1 < n; x1++)
    {
        int l = lower_bound(pos.begin(), pos.end(), pos[x1]-k) - pos.begin() - 1;
        ll left = (l < 0? 0 : mx.query(0, l));
        int r = upper_bound(pos.begin(), pos.end(), pos[x1]+k) - pos.begin();
        ll right = (r == n? 0 : mx.query(r, n-1));
        ll tmp = eat[x1] + max(left, right);
        // cerr << var(x1) << var(tmp) << endl;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

