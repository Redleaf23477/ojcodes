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

ll L, R;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> L >> R;
}

ll S(ll x) { return x*(x+1)/2; }

bool ok(ll guess, ll &n, ll &ansl, ll &ansr)
{
    ll mx = max(L, R), mn = min(L, R);
    // big
    ll low = 1, high = guess, mid, bp = 0;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(S(mid) <= mx && mx-mn-S(mid-1) > 0) bp = mid, low = mid+1;
        else high = mid-1;
    }
    // sim
    ll l, r;
    if(L == mx)
    {
        l = L - S(bp);
        r = R;
    }
    else
    {
        l = L;
        r = R - S(bp);
    }
    ll &big = (l >= r)? l : r;
    ll &small = (l >= r)? r : l;
    {
        if((bp+1)%2 == guess%2)
        {
            if(bp+1 <= guess) big -= (bp+1 + guess) * (guess - bp -1 + 2)/2 /2;
            if(bp+2 <= guess-1) small -= (bp+2 + guess-1) * (guess - bp - 3 + 2)/2 /2;
        }
        else
        {
            if(bp+2 <= guess) small -= (bp+2 + guess) * (guess - bp - 2 + 2)/2 /2;
            if(bp+1 <= guess-1) big -= (bp+1 + guess-1) * (guess - bp - 2 + 2)/2 /2;
        }
    }
    if(l < 0 || r < 0) return false;
    /*
    for(ll i = bp+1; i <= guess; i++)
    {
        if(l >= r) l -= i;
        else r -= i;
        if(l < 0 || r < 0) return false;
    }
    */
//    cerr << var(guess) << var(bp) << endl;
    if(guess > n)
    {
        n = guess;
        ansl = l, ansr = r;
    }
    return true;
}

void process()
{
    ll low = 1, high = 1e9, mid, n = 0, l, r;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid, n, l, r)) low = mid+1;
        else high = mid-1;
    }
    cout << n << " " << l << " " << r << endl;
}

