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

ll n, l, r;

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
    cin >> n >> l >> r;
}

void process()
{
    ll acc = 0;
    for(ll i = 1; acc < r; i++)
    {
        if(i == n)
        {
            cout << 1 << " "; acc++;
            continue;
        }
        ll len = 2*(n-i);
        if(acc + len < l) 
        {
            acc += len; continue;
        }
        for(ll j = i+1; j <= n; j++)
        {
            if(acc+1 >= l) cout << i << " "; 
            acc++;
            if(acc == r) break;
            if(acc+1 >= l) cout << j << " "; 
            acc++;
            if(acc == r) break;
        }
    }
    cout << endl;
}
