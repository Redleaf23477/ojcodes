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
        int n; ll w; cin >> n >> w;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        ll ans = 0, sav = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(arr[i] >= w)
            {
                ans++;
                sav += arr[i] - w;
            }
            else if(sav >= w - arr[i])
            {
                ans++;
                sav -= w - arr[i];
            }
            else break;
        }
        cout << ans << endl;
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

