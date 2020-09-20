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
using LL = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    init();
    for(int t = 1; t <= T; t++)
    {
        process();
    }
    cout.flush();
    return 0;
}

vector<LL> build(1, 0);

void init()
{
    for(int i = 0; i < 32; i++)
    {
        build.emplace_back(2*build[i] + (1ll<<i)*(1ll<<i));
    }
}

void process()
{
    long long x; cin >> x;
    int ans = 0;
    for(int i = 1; i < (int)build.size(); i++)
    {
        if(x >= build[i]) ans++, x-= build[i];
        else break;
    }
    cout << ans << endl;
}

