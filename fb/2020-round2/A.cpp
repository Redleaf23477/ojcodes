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

ll N, K;
ll AS, BS, CS, DS;
ll AX, BX, CX, DX;
ll AY, BY, CY, DY;
vector<ll> S, X, Y;

void init()
{
    cin >> N >> K;
    S.assign(N, 0), X.assign(N, 0), Y.assign(N, 0);
    for(int i = 0; i < K; i++) cin >> S[i];
    cin >> AS >> BS >> CS >> DS;
    for(int i = 0; i < K; i++) cin >> X[i];
    cin >> AX >> BX >> CX >> DX;
    for(int i = 0; i < K; i++) cin >> Y[i];
    cin >> AY >> BY >> CY >> DY;
    for(int i = K; i < N; i++)
    {
        S[i] = (AS*S[i-2] + BS*S[i-1] + CS) % DS;
        X[i] = (AX*X[i-2] + BX*X[i-1] + CX) % DX;
        Y[i] = (AY*Y[i-2] + BY*Y[i-1] + CY) % DY;
    }

    /*
    cerr << endl;
    cerr << "S = ";
    for(auto x : S) cerr << x << " "; cerr << endl;
    cerr << "X = ";
    for(auto x : X) cerr << x << " "; cerr << endl;
    cerr << "Y = ";
    for(auto x : Y) cerr << x << " "; cerr << endl;
    */
}

void process()
{
    ll tooMuch = 0, tooLess = 0, left = 0, canGo = 0;
    for(int i = 0; i < N; i++)
    {
        ll l = X[i], r = X[i]+Y[i];
        /*
        cerr << var(i) << endl;
        */
        if(S[i] > r) // too much
        {
            tooMuch += S[i] - r;
            canGo += Y[i];
            /*
            cerr << "tooMuch " << S[i]-r << endl;
            cerr << "canGo " << Y[i] << endl;
            */
        }
        else if(S[i] < l) // too less
        {
            tooLess += l - S[i];
            left += Y[i];
            /*
            cerr << "tooLess " << l-S[i] << endl;
            cerr << "left " << Y[i] << endl;
            */
        }
        else // ok
        {
            left += r - S[i];
            canGo += S[i] - l;
            /*
            cerr << "left " << r-S[i] << ", canGo " << S[i]-l << endl;
            */
        }
    }
    
    ll ans = 0;

    // tooMuch -> tooLess
    {
        ll go = min(tooMuch, tooLess);
        ans += go;
        tooMuch -= go, tooLess -= go;
        /*
        cerr << "tooMuch -> tooLess: " << go << endl;
        */
    }
    /*
    cerr << var(tooMuch) << var(tooLess) << var(left) << var(canGo) << endl;
    */
    if(tooMuch > 0)
    {
        if(tooMuch > left)
        {
            cout << -1 << endl; return;
        }
        ans += tooMuch;
    }
    if(tooLess > 0)
    {
        if(tooLess > canGo)
        {
            cout << -1 << endl; return;
        }
        ans += tooLess;
    }

    cout << ans << endl;
}
