// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

const ll MOD = 998244353;

ll len;
vector<ll> pw10;

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
    cin >> len;
    pw10.resize(len+1);
    pw10[0] = 1;
    for(int i = 1; i <= len; i++) pw10[i] = pw10[i-1] * 10 % MOD;
}

ll run(ll d)
{
    if(d == len)
    {
        return 10;
    }
    ll ans = 0;
    ans = 2 * 10 * 9 % MOD * pw10[len-d-1] % MOD;
    if(len-d >= 2)
    {
        ans = (ans + (len-d+1-2) * 10 * 9 * 9 % MOD * pw10[len-d-2] % MOD)%MOD;
    }
    return ans;
}

void process()
{
    for(int i = 1; i <= len; i++)
        cout << run(i) << " ";
    cout << endl;
}

