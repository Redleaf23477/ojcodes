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

ll n, k;
map<ll,ll> mp;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        if(mp.count(x) == 0) mp[x] = 0;
        mp[x]++;
    }
}

void process()
{
    ll lsum = 0, lcnt = 0, rsum = 0, rcnt = n, ans = 1ll<<60;
    for(auto p : mp) rsum += p.first * p.second;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        auto p = *it;

        rsum -= p.first * p.second;
        rcnt -= p.second;

        ll need = k - p.second;
        if(need <= 0) 
        {
            ans = 0;
            break;
        }

        // from low
        if(lcnt > 0)
        {
            if(need <= lcnt)
            {
                ll use = (p.first-1) * lcnt - lsum + need;
                ans = min(ans, use);
//                cerr << var(p.first) << " case1 " << var(use) << endl;
            }
            else
            {
                ll use = p.first * lcnt - lsum + rsum - (p.first+1) * rcnt;
                ll still = need - lcnt;
                use += still;
                ans = min(ans, use);
//                cerr << var(p.first) << " case2 " << var(use) << endl;
            }
        }
        
        // from high
        if(rcnt > 0)
        {
            if(need <= rcnt)
            {
                ll use = rsum - (p.first+1) * rcnt + need;
                ans = min(ans, use);
 //               cerr << var(p.first) << " case3 " << var(use) << endl;
            }
            else
            {
                ll use = rsum - p.first * rcnt + (p.first-1) * lcnt - lsum;
                ll still = need - rcnt;
                use += still;
                ans = min(ans, use);
//                cerr << var(p.first) << " case4 " << var(use) << endl;
            }
        }

        lsum += p.first * p.second;
        lcnt += p.second;
    }
    cout << ans << endl;
}

