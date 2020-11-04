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

int n; 
LL k;
vector<pair<LL,LL>> arr;

void init()
{
    cin >> n >> k;
    arr.resize(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
}

void process()
{
    LL ans = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        if(r > arr[i].second) continue;
        if(r > arr[i].first) arr[i].first = r;
        LL add = (arr[i].second - arr[i].first + k - 1) / k;
        ans += add;
        r = arr[i].first + k * add;
    }
    cout << ans << endl;
}

