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
double P;

void init()
{
    cin >> N >> P;
}

double C2(double x) { return x*(x-1)/2.0; }

double f(int a, int b)
{
    if(a < 0 || b < 0) return 0;
    if(a == 0 && b == 0) return 0;
    double ans = 1;
    int n = a+b+1;
    // pass
    ans += C2(a) / C2(n) * f(a-1, b);
    ans += C2(b) / C2(n) * f(a, b-1);
    ans += a * b / C2(n) * (P * f(a-1, b) + (1-P) * f(a, b-1));
    // strong
    ans += b / C2(n) * (1-P) * f(a, b-1);
    // weak
    ans += a / C2(n) * P * f(a-1, b);

    return ans;
}

void process()
{
    for(int i = 0; i < N; i++)
        cout << f(i, N-i-1) << endl;
}

