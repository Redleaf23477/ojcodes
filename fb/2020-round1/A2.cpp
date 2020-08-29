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

struct Seg1D_Dyn
{
    struct Node
    {
        bool hasTag;
        ll val, tag;
        ll l, r;
        Node *lson, *rson;
        Node(ll _l, ll _r):l(_l), r(_r)
        {
            hasTag = false;
            val = tag = 0;
            lson = rson = nullptr;
        }
        ~Node()
        {
            if(lson) { delete lson; lson = nullptr; }
            if(rson) { delete rson; rson = nullptr; }
        }
    };
    Node *rt;
    Seg1D_Dyn(ll l, ll r)
    {
        rt = new Node(l, r);
    }
    ~Seg1D_Dyn()
    {
        delete rt;
    }
    void up(Node *o)
    {
        ll sum = 0;
        if(o->lson)
        {
            if(o->lson->hasTag) sum += (o->lson->r - o->lson->l + 1) * (o->lson->tag);
            else sum += (o->lson->val);
        }
        if(o->rson)
        {
            if(o->rson->hasTag) sum += (o->rson->r - o->rson->l + 1) * (o->rson->tag);
            else sum += (o->rson->val);
        }
        o->val = sum;
    }
    void down(Node *o)
    {
        if(o->l == o->r) return;
        int mid = (o->l + o->r)/2;
        // build child if needed
        if(o->lson == nullptr)
            o->lson = new Node(o->l, mid);
        if(o->rson == nullptr)
            o->rson = new Node(mid+1, o->r);
        if(o->hasTag)
        {
            // update child
            o->lson->hasTag = o->rson->hasTag = true;
            o->lson->tag = o->rson->tag = o->tag;
            // update self
            o->val = (o->r - o->l + 1) * (o->tag);
            o->hasTag = false;
        }
    }
    ll query(Node *o, ll L, ll R)
    {
        if(o->r < L || R < o->l) return 0;
        if(L <= o->l && o->r <= R)
        {
            if(o->hasTag) return (o->r - o->l + 1) * (o->tag);
            else return o->val;
        }
        down(o);
        ll sum = 0;
        if(o->lson)
            sum += query(o->lson, L, R);
        if(o->rson)
            sum += query(o->rson, L, R);
        return sum;
    }
    void modify(Node *o, ll L, ll R, ll v)
    {
        if(o->r < L || R < o->l) return;
        if(L <= o->l && o->r <= R)
        {
            o->hasTag = true;
            o->tag = v;
            return;
        }
        down(o);
        if(o->lson) modify(o->lson, L, R, v);
        if(o->rson) modify(o->rson, L, R, v);
        up(o);
    }
    // for calling
    ll query(ll L, ll R) { return query(rt, L, R); }
    void modify(ll L, ll R, ll v) { modify(rt, L, R, v); }
};

/*
struct Seg1D
{
    struct Node
    {
        bool hasTag;
        ll val, tag;
    };
    int n;
    vector<Node> st;
    void up(int l, int r, int idx)
    {
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        ll sum = 0;
        if(st[lson].hasTag) sum += st[lson].tag * (mid-l+1);
        else sum += st[lson].val;
        if(st[rson].hasTag) sum += st[rson].tag * (mid-l+1);
        else sum += st[rson].val;
        st[idx].val = sum;
    }
    void down(int l, int r, int idx)
    {
        int lson = idx*2, rson = idx*2+1;
        if(st[idx].hasTag)
        {
            st[idx].val = st[idx].tag * (r-l+1);
            st[lson].hasTag = st[rson].hasTag = true;
            st[lson].tag = st[rson].tag = st[idx].tag;
            st[idx].hasTag = false;
        }
    }
    void build(int _n)
    {
        n = _n;
        st.assign(4*n, {false, 0, 0});
    }
    ll query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) 
        {
            if(st[idx].hasTag) return st[idx].tag * (r-l+1);
            else return st[idx].val;
        }
        down(l, r, idx);
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        return query(l, mid, lson, L, R) + query(mid+1, r, rson, L, R);
    }
    void modify(int l, int r, int idx, int L, int R, ll v)
    {
        if(r < L || R < l) return;
        if(L <= l && r <= R) 
        {
            st[idx].hasTag = true;
            st[idx].tag = v;
            return;
        }
        down(l, r, idx);
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        modify(l, mid, lson, L, R, v);
        modify(mid+1, r, rson, L, R, v);
        up(l, r, idx);
    }
    // for calling
    ll query(int L, int R)
    {
        return query(0, n-1, 1, L, R);
    }
    void modify(int L, int R, ll v)
    {
        modify(0, n-1, 1, L, R, v);
    }
};
*/

const ll MOD = 1e9+7;

ll N, K;
ll AL, BL, CL, DL;
ll AH, BH, CH, DH;
ll AW, BW, CW, DW;
ll mn, mx;
vector<ll> L, H, W, P;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> N >> K;
    L.assign(N, 0), H.assign(N, 0), W.assign(N, 0), P.assign(N, 0);
    for(int i = 0; i < K; i++) cin >> L[i];
    cin >> AL >> BL >> CL >> DL;
    for(int i = 0; i < K; i++) cin >> W[i];
    cin >> AW >> BW >> CW >> DW;
    for(int i = 0; i < K; i++) cin >> H[i];
    cin >> AH >> BH >> CH >> DH;
    for(int i = K; i < N; i++)
    {
        L[i] = (AL * L[i-2] + BL * L[i-1] + CL) % DL + 1;
        W[i] = (AW * W[i-2] + BW * W[i-1] + CW) % DW + 1;
        H[i] = (AH * H[i-2] + BH * H[i-1] + CH) % DH + 1;
    }
    mn = (1ll<<60), mx = 0;
    for(int i = 0; i < N; i++)
    {
        mn = min(L[i], mn);
        mx = max(L[i]+W[i], mx);
    }
    /*
    cerr << "L = [ ";
    for(auto l : L) cerr << l << " ";
    cerr << "]" << endl;
    cerr << "W = [ ";
    for(auto w : W) cerr << w << " ";
    cerr << "]" << endl;
    cerr << "H = [ ";
    for(auto h : H) cerr << h << " ";
    cerr << "]" << endl;
    */
}

void process()
{
    ll sum = 0; // for LR
    Seg1D_Dyn UD(mn, mx), LR(mn, mx), plug(mn, mx+1);
    for(int i = 0; i < N; i++)
    {
        ll l = L[i], r = L[i]+W[i];
        // LR
        // substract
        ll sub = LR.query(l, r); sum -= sub * H[i]; 
        // squash
        LR.modify(l, r, 0);
        // add
        ll ql = plug.query(l, l);
        if(ql == 0 || ql == 2) 
        {
            LR.modify(l, l, 1), sum += H[i];
            // cerr << "plug at " << l << endl;
        }
        ll qr = plug.query(r, r);
        if(qr == 0 || qr == 3)
        {
            LR.modify(r, r, 1), sum += H[i];
            // cerr << "plug at " << r << endl;
        }
        plug.modify(l, r, 1);
        if(ql == 0 || ql == 2) plug.modify(l, l, 2);
        if(qr == 0 || qr == 3) plug.modify(r, r, 3);
        // update P[i]
        P[i] = (P[i] + sum) % MOD;

        // UD
        l = L[i], r = L[i]+W[i]-1;
        UD.modify(l, r, 1);
        ll ud = UD.query(mn, mx);
        P[i] = (P[i] + 2*ud) % MOD;
    }

    // gen answer
    ll ans = 1;

    /*
    cerr << "P = [ ";
    for(auto p : P) cerr << p << " ";
    cerr << "]" << endl;
    */

    for(auto p : P)
        ans = ans * p % MOD;
    cout << ans << endl;
}

