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

ll t;

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
    cin >> t;
}

bool grow(ll day, bool print = false)
{
    vector<ll> ans(day, 0);
    ll rest = t - day - 1;
    ll num = 1;
    for(int i = 0; i < day; i++)
    {
        ll d = min(num, rest / (day-i));
        rest -= d * (day-i);
        ans[i] = d;
        num += d;
    }
    if(print)
    {
        cout << day << endl;
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
    if(rest > 0) return false;
    else return true;
}

void process()
{
    ll low = 1, high = min(t, 100000ll), mid, ans = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(grow(mid))
        {
            ans = mid, high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    if(ans == -1) cout << ans << endl;
    else grow(ans, true);
}

