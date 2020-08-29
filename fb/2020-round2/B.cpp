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
        cout << "Case #" << t << ":" << endl;
        init();
        process();
    }
    cout.flush();
    return 0;
}

int N;
double P, Q;

void init()
{
    cin >> N >> P;
    Q = 1-P;
}

double C2(double x) { return x*(x-1)/2.0; }

void process()
{
    using TII = tuple<int,int>;
    vector<map<TII, double>> dp(N+1);
    dp[1][TII(0, 0)] = 0;
    for(int n = 2; n <= N; n++)
    {
        for(int a = 0; a < n; a++)
        {
            int b = n-a-1;
            dp[n][TII(a, b)] = 1 + (
                    dp[n-1][TII(a-1, b)] * (C2(a) + a*b*P + a*P) +
                    dp[n-1][TII(a, b-1)] * (C2(b) + a*b*Q + b*Q)
                    ) / C2(n);
        }
    }

    for(int i = 0; i < N; i++)
        cout << fixed << setprecision(8) << dp[N][TII(i, N-1-i)] << endl;
}

