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

const ll MOD = 1e9+7;

ll N, K, W;
ll AL, BL, CL, DL;
ll AH, BH, CH, DH;
vector<ll> L, H, P;

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
    cin >> N >> K >> W;
    L.assign(N, 0), H.assign(N, 0), P.assign(N, 0);
    for(int i = 0; i < K; i++) cin >> L[i];
    cin >> AL >> BL >> CL >> DL;
    for(int i = 0; i < K; i++) cin >> H[i];
    cin >> AH >> BH >> CH >> DH;
    for(int i = K; i < N; i++)
    {
        L[i] = (AL * L[i-2] + BL * L[i-1] + CL) % DL + 1;
        H[i] = (AH * H[i-2] + BH * H[i-1] + CH) % DH + 1;
    }
    /*
    cerr << "L = [ ";
    for(auto l : L) cerr << l << " ";
    cerr << "]" << endl;
    cerr << "H = [ ";
    for(auto h : H) cerr << h << " ";
    cerr << "]" << endl;
    */
}

void UD()
{
    ll sum = 0;
    ll r = 0;
    for(int i = 0; i < N; i++)
    {
        if(L[i] >= r)
        {
            sum = (sum + W) % MOD;
        }
        else
        {
            sum = (sum + L[i] + W - r) % MOD;
        }
        r = L[i] + W;

        P[i] = (P[i] + 2*sum) % MOD;

        /*
        cerr << var(2*sum) << endl;
        */
    }
}

void LR()
{
    deque<ll> dq;
    ll sum = 0;
    for(int i = 0; i < N; i++)
    {
        while(!dq.empty() && L[dq.front()]+W < L[i]) dq.pop_front();
        /*
        cerr << "LR: dq = "; for(auto d : dq) cerr << d << " "; cerr << endl;
        */
        
        if(dq.empty())
        {
            sum = (sum + 2*H[i]) % MOD;
        }
        else
        {
            while(dq.size() > 1 && H[dq.back()] <= H[i]) dq.pop_back();
            if(dq.size() == 1 && H[dq.back()] <= H[i])
            {
                sum = (sum - 2*H[dq.back()] + 2*H[i]) % MOD;
                dq.pop_back();
            }
        }
        dq.push_back(i);

        P[i] = (P[i] + sum) % MOD;

        /*
        cerr << "LR" << var(sum) << endl;
        */
    }
}

void process()
{
    UD();
    LR();
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

