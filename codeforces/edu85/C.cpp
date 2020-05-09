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
using P = pair<ll,ll>;
#define hp first
#define exp second

int n;
vector<P> arr;

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
    arr.resize(n);
    for(auto &x : arr) cin >> x.hp >> x.exp;
}

void process()
{
    ll cnt = 0, trigger = 1ll<<60;
    for(int i = 0; i < n; i++)
    {
        int prv = (i+n-1)%n;
        if(arr[i].hp > arr[prv].exp)
        {
            cnt += arr[i].hp - arr[prv].exp;
            trigger = min(trigger, arr[prv].exp);
        }
        else trigger = min(trigger, arr[i].hp);
    }
    cout << cnt + trigger << endl;
}

