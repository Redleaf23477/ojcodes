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

ll build(ll h)
{
    return (3+3*h)*h/2 - h;
}

void process()
{
    int cnt = 0;
    while(true)
    {
        ll low = 1, high = 100000, mid, ans = -1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(n < build(mid)) high = mid-1;
            else ans = mid, low = mid+1;
        }
        if(ans == -1) break;
        cnt++;
        n -= build(ans);
    }
    cout << cnt << endl;
}

