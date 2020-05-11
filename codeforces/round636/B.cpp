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

ll n;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
}

void process()
{
    if(n/2 % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll sum = 0;
    for(int i = 1; i <= n/2; i++) 
    {
        cout << i*2 << " ";
        sum += i*2;
    }
    for(int i = 1; i < n/2; i++)
    {
        cout << i*2-1 << " ";
        sum -= i*2-1;
    }
    cout << sum << endl;
}

