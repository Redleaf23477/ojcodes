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

ll N, M, E, K;
ll AX, BX, CX;
ll AY, BY, CY;
ll AI, BI, CI;
ll AW, BW, CW;
vector<ll> X, Y, I, W;

void init()
{
    cin >> N >> M >> E >> K;
    X.assign(N, 0), Y.assign(N, 0), I.assign(E, 0), W.assign(E, 0);
    for(int i = 0; i < K; i++) cin >> X[i];
    cin >> AX >> BX >> CX;
    for(int i = 0; i < K; i++) cin >> Y[i];
    cin >> AY >> BY >> CY;
    for(int i = 0; i < K; i++) cin >> I[i];
    cin >> AI >> BI >> CI;
    for(int i = 0; i < K; i++) cin >> W[i];
    cin >> AW >> BW >> CW;
    for(int i = K; i < N; i++)
    {
        X[i] = (AX*X[i-2] + BX*X[i-1] + CX) % M;
        Y[i] = (AY*Y[i-2] + BY*Y[i-1] + CY) % M;
    }
    for(int i = K; i < E; i++)
    {
        I[i] = (AI*I[i-2] + BI*I[i-1] + CI) % (N*M+N);
        W[i] = (AW*W[i-2] + BW*W[i-1] + CW) % 1000000000ll;
    }

    /*
    cerr << endl;
    cerr << "X = ";
    for(auto x : X) cerr << x << " ";
    cerr << endl;
    cerr << "Y = ";
    for(auto x : Y) cerr << x << " ";
    cerr << endl;
    cerr << "I = ";
    for(auto x : I) cerr << x << " ";
    cerr << endl;
    cerr << "W = ";
    for(auto x : W) cerr << x << " ";
    cerr << endl;
    */
}

void process()
{
    ll ans = 1;

    map<int, ll> mp;
    vector<multiset<ll>> group(N+1);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            mp[i*M+j] = 1;
            group[i].insert(1);
        }
    }
    for(int i = 0; i < N; i++)
    {
        mp[N*M+i] = 1;
        group[N].insert(1);
    }

    ll mst = N*M-1;

    for(int e = 0; e < E; e++)
    {
        int bye = I[e];
        ll new_w = W[e];
        ll bye_w = mp[bye];

        int gid = (bye >= N*M? N : bye / M);
        auto it = group[gid].end(); it--;

        if(*it != bye_w)
        {
            mst -= bye_w;
            mst += *it;
        }

        mp[bye] = new_w;
        group[gid].erase(group[gid].find(bye_w));

        ans = (ans * mst) % MOD;
    }

    cout << ans << endl;
}

