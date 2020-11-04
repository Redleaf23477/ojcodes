//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const ll INF = 1ll << 60;
const ll MOD = (ll)1e9 + 7;

template<typename Ty = long long int>
struct Linear {
// private:
    Ty a, b;
// public:
    Linear(Ty _a, Ty _b):a(_a), b(_b) {}
    Ty operator()(Ty x) { return a*x+b; }
    tuple<Ty, Ty> inter(Linear &that)
    {
        ll up = that.b-this->b;
        ll down = this->a-that.a;
        if(down < 0) up *= -1, down *= -1;
        return make_tuple(up, down);
    }
};

template<typename Ty = long long int>
struct ConvexHull
{
// private:
    using L = Linear<Ty>;
    vector<L> hull;
// public:
    size_t size() { return hull.size(); }
    void push_back(L h)
    {
        while(hull.size() >= 2)
        {
            auto &f = hull.end()[-2];
            auto &g = hull.end()[-1];  // back
            // x of inter(h, f) <= x of inter(f, g)
            Ty a, b, c, d;
            tie(a, b) = h.inter(f);
            tie(c, d) = f.inter(g);
            // inter_hf.first / inter_hf.second <= inter_fg.first / inter_fg.second
            if((__int128)a*d <= (__int128)b*c) hull.pop_back();
            else break;
        }
        hull.push_back(h);
    }
    void add_a(Ty a)
    {
        for(auto &h : hull) h.a += a;
    }
    Ty operator() (Ty x)
    {
        assert(!hull.empty() && "GG empty convex hull");
        // trinary search
        int a = 0, b, c, d = (int)hull.size()-1;
        while(d-a >= 3)
        {
            int len = (d-a)/3;
            b = a + len, c = b + len;
            if(hull[b](x) <= hull[c](x)) a = b;
            else d = c;
        }
        Ty ans = hull[a](x);
        for(int i = a+1; i <= d; i++) ans = min(ans, hull[i](x));
        return ans;
    }
};

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

ll N, M, K;
vector<ll> H;
vector<vector<tuple<int, ll>>> tree;
vector<vector<tuple<int,int>>> query; // query[x] = { (y, i-th) }
vector<ConvexHull<ll>> hull;
vector<ll> ans;

void print(string str, vector<ll> &arr)
{
    cerr << str << " = ";
    for(auto x : arr) cerr << x << " ";
    cerr << endl;
}

void init()
{
    // clean up
    H.clear(), tree.clear(), query.clear(), hull.clear(), ans.clear();

    // input
    vector<ll> P, L, X, Y;
    ll AP, BP, CP;
    ll AL, BL, CL, DL;
    ll AH, BH, CH, DH;
    ll AX, BX, CX;
    ll AY, BY, CY, DY;

    cin >> N >> M >> K;

    P.assign(N, 0), L.assign(N, 0), H.assign(N, 0);
    X.assign(M, 0), Y.assign(M, 0);
    ans.assign(M, INF);
    hull.resize(N);

    for(int i = 0; i < K; i++) cin >> P[i];
    cin >> AP >> BP >> CP;
    for(int i = 0; i < K; i++) cin >> L[i];
    cin >> AL >> BL >> CL >> DL;
    for(int i = 0; i < K; i++) cin >> H[i];
    cin >> AH >> BH >> CH >> DH;
    for(int i = 0; i < K; i++) cin >> X[i];
    cin >> AX >> BX >> CX;
    for(int i = 0; i < K; i++) cin >> Y[i];
    cin >> AY >> BY >> CY >> DY;

    for(int i = K; i < N; i++)
    {
        P[i] = (AP*P[i-2] + BP*P[i-1] + CP) % (i-1) + 1;
        L[i] = (AL*L[i-2] + BL*L[i-1] + CL) % DL + 1;
        H[i] = (AH*H[i-2] + BH*H[i-1] + CH) % DH + 1;
    }
    for(int i = K; i < M; i++)
    {
        X[i] = (AX*X[i-2] + BX*X[i-1] + CX) % N + 1;
        Y[i] = (AY*Y[i-2] + BY*Y[i-1] + CY) % DY + 1;
    }
    // 1-base to 0-base
    for(int i = 0; i < N; i++) P[i]--;
    for(int i = 0; i < M; i++) X[i]--;

    // debug
    print("P", P);
    print("L", L);
    print("H", H);
    print("X", X);
    print("Y", Y);

    // build tree
    tree.resize(N);
    for(int i = 1; i < N; i++)
    {
        tree[P[i]].emplace_back(i, L[i]);
    }

    // query
    query.resize(N);
    for(int i = 0; i < M; i++)
    {
        query[X[i]].emplace_back(Y[i], i);
    }
}

void dfs(int u)
{
    if(tree[u].size() == 0)
    {
        hull[u].push_back(Linear<ll>(0, 0));
        return;
    }
    int mxIdx = -1;
    for(auto [v, w] : tree[u])
    {
        dfs(v);
        hull[v].add_a(w);
        if(mxIdx == -1 || hull[mxIdx].size() < hull[v].size())
            mxIdx = v;
    }
    hull[u].hull.swap(hull[mxIdx].hull);
    for(auto [v, _] : tree[u])
    {
        if(v == mxIdx) continue;
        for(auto l : hull[v].hull) hull[u].push_back(l);
    }

    ll me = hull[u](H[u]);

    cerr << "convex hull at node " << u << ": ";
    for(auto l : hull[u].hull) cerr << "(" << l.a << "," << l.b << ") ";
    cerr << endl;

    for(auto [q, i] : query[u])
    {
        ans[i] = min(me, hull[u](q));
    }

    hull[u].push_back(Linear<ll>(0, me));
}

void process()
{
    dfs(0);
    ll out = 1;
    for(int i = 0; i < M; i++) out = out * (ans[i]+1) % MOD;
    cout << out << endl;
}

