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
using LL = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, q;
vector<int> arr, qry;

void init()
{
    cin >> n >> q;
    arr.resize(n), qry.resize(q);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < q; i++) cin >> qry[i];
    sort(arr.begin(), arr.end());
}

bool good(int guess)
{
    int leq = 0, gt = 0;
    for(auto x : arr)
    {
        if(x <= guess) leq++;
        else gt++;
    }
    for(auto k : qry)
    {
        if(k > 0)
        {
            if(k <= guess) leq++;
            else gt++;
        }
        else
        {
            k = -k;
            if(k <= leq) leq--;
            else gt--;
        }
    }
    return leq > 0;
}

void process()
{
    int low = 1, high = n, mid, ans = 0;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(good(mid) == 0) low = mid+1;
        else ans = mid, high = mid-1;
    }
    cout << ans << endl;
}

