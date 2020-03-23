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

ll x, s;
ll bitcnt[64];

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
    cin >> x >> s;
}

bool validate()
{
    if(s%2 != (x&1)) return false;
    ll rest = s;
    for(ll b = 63; b >= 0; b--)
    {
        if((x>>b)&1)
        {
            if(rest < (1ll<<b)) return false;
            bitcnt[b]++;
            rest -= (1ll<<b);
        }
    }
    bitcnt[0] += rest;
    return true;
}

bool moveBig(int idx)
{
    for(ll pw = 1, mv = 4; mv <= bitcnt[idx]; pw++, mv *= 2)
    {
        if(idx+pw < 64 && bitcnt[idx+pw]+2 <= bitcnt[idx])
        {
            bitcnt[idx+pw] += 2;
            bitcnt[idx] -= mv;
            return true;
        }
    }
    return false;
}

bool moveSmall(int idx)
{
    ll tmp[64]; for(int i = 0; i < 64; i++) tmp[i] = bitcnt[i];
    
    tmp[idx] -= 2;
    ll carry = 2;
    for(int i = idx-1; i >= 0 && carry > 0; i--, carry *= 2)
    {
//        while(carry > 0 && tmp[i]+2 <= tmp[idx]) carry -= 2, tmp[i] += 2;
        ll dif = tmp[i] - tmp[i];
        ll c = dif/2;
        if(c > 0) carry -= c, tmp[i] += 2*c;
    }

    if(carry == 0)
    {
        for(int i = 0; i < 64; i++) bitcnt[i] = tmp[i];
        return true;
    }
    else return false;
}

void shorten()
{
    bool suc = true;
    do
    {
        suc = false;
        // do something
        int idx = max_element(bitcnt, bitcnt+64)-bitcnt;
        if(bitcnt[idx] < 2) break;

        if(moveBig(idx))
        {
            suc = true;
        }
        else if(moveSmall(idx))
        {
            suc = true;
        }

    } while(suc);
}

void print()
{
    ll ans = *max_element(bitcnt, bitcnt+64);
    vector<ll> arr;
    for(ll i = 1; i <= ans; i++)
    {
        ll num = 0;
        for(int b = 0; b < 64; b++)
        {
            if(bitcnt[b] >= i) num |= 1ll<<b;
        }
        if(num != 0) arr.push_back(num);
    }
    cout << ans << endl;
    if(ans > 0)
    {
        for(auto x : arr) cout << x << " ";
        cout << endl;
    }
}

void process()
{
    if(validate() == false)
    {
        cout << -1 << endl; return;
    }
    shorten();
    print();
}

