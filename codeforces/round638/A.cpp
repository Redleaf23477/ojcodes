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
    while(T--)
    {
        int n; cin >> n;
        int big = (1<<n);
        for(int i = 1; i < n/2; i++) big += (1<<i);
        cout << big - ((1<<(n+1))-1-1-big) << endl;
    }
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
}

