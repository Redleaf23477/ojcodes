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

const ll MOD = (ll)1e9+7;

int n, m;
vector<ll> sum3, sum2;

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
    cin >> n >> m;
    sum3.assign(n+1, 0);
    sum2.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        sum3[i] = (sum3[i-1] + i*i*i%MOD) %MOD;
        sum2[i] = (sum2[i-1] + i*i%MOD) %MOD;
    }
}

inline ll toPos(ll x) { x %= MOD; return (x < 0? x+MOD : x); }

ll fac3(ll x) { return 1; }
ll fac2(ll x) { return toPos(-3*x + 6); }
ll fac1(ll x) { return toPos(3*x*x - 12*x + 11); }
ll fac0(ll x) { return toPos(-1*x*x*x + 6*x*x - 11*x + 6); }

inline void add_self(ll &a, ll y) { a = toPos(a + y); }
inline void sub_self(ll &a, ll y) { a = toPos(a - y); }
inline ll mul(ll x, ll y) { return toPos(x) * toPos(y) % MOD; }

void flush(vector<tuple<int,int,int>> &buff, vector<ll> &arr)
{
    vector<vector<ll>> tmp(4, vector<ll>(n+2, 0));
    for(auto [cmd, x, y] : buff)
    {
        ll sign = (cmd == 1? 1 : -1);
        // i^3
        add_self(tmp[3][x], sign * fac3(x));
        sub_self(tmp[3][y+1], sign * fac3(x));
        // i^2
        add_self(tmp[2][x], sign * fac2(x));
        sub_self(tmp[2][y+1], sign * fac2(x));
        // i^1
        add_self(tmp[1][x], sign * fac1(x));
        sub_self(tmp[1][y+1], sign * fac1(x));
        // i^0
        add_self(tmp[0][x], sign * fac0(x));
        sub_self(tmp[0][y+1], sign * fac0(x));
    }
    /*
    cerr << "tmp: " << endl;
    for(int i = 0; i < 4; i++)
    {
        cerr << "tmp[" << i << "] : ";
        for(auto x : tmp[i]) cerr << x << " ";
        cerr << endl;
    }
    */
    for(auto &t : tmp)
        for(int i = 1; i <= n; i++)
            add_self(t[i], t[i-1]);
    vector<ll> sum(n+1, 0);
    for(ll i = 1; i <= n; i++)
    {
        for(ll p = 0, x = 1; p <= 3; p++, x = mul(x, i))
            add_self(sum[i], mul(x, tmp[p][i]));
        add_self(sum[i], sum[i-1]);
    }
    /*
    cerr << "sum: " << endl;
    for(auto x : sum) cerr << x << " ";
    cerr << endl;
    */
    for(ll i = 1; i <= n; i++) add_self(arr[i], sum[i]);
    /*
    cerr << "arr: " << endl;
    for(auto x : arr) cerr << x << " ";
    cerr << endl;
    */
    buff.clear();
}

ll run(int L, int R, vector<tuple<int,int,int>> &buff, vector<ll> &acc)
{
    ll ans = toPos(acc[R] - acc[L-1]);
    vector<ll> tmp(4, 0);
    for(auto [cmd, x, y] : buff)
    {
        if(y < L || R < x) continue;
        int l = max(x, L), r = min(y, R);
        ll sign = (cmd == 1? 1 : -1);
        // i^3
        add_self(ans, toPos(sign * mul(fac3(x), (sum3[r] - sum3[l-1]))));
        // i^2
        add_self(ans, toPos(sign * mul(fac2(x), (sum2[r] - sum2[l-1]))));
        // i^1
        add_self(ans, toPos(sign * mul(fac1(x), (l+r) * (r-l+1) / 2)));
        // i^0
        add_self(ans, toPos(sign * mul(fac0(x), (r - l + 1))));
    }
    return ans;
}

void process()
{
    vector<ll> acc(n+1, 0);
    vector<tuple<int,int,int>> buff;
    while(m--)
    {
        int cmd, l, r; cin >> cmd >> l >> r;
        if(cmd == 0)
        {
            cout << run(l, r, buff, acc) << endl;
        }
        else
        {
            buff.emplace_back(cmd, l, r);
            // if((int)buff.size() >= (int)sqrt(n))
                flush(buff, acc);
            for(auto x : acc) cerr << x << " ";
            cerr << endl;
        }
    }
}

