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

void init()
{
}

void process()
{
    int n; cin >> n;
    vector<int> arr(n); for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    vector<int> ans(n);
    int cnt = 0, j = 0;
    for(int i = 1; i < n; i += 2)
    {
        ans[i] = arr[j];
        j++;
        if(i-1 >= 0 && i+1 < n) cnt++;
    }
    for(int i = 0; i < n; i+= 2)
    {
        ans[i] = arr[j];
        j++;
    }
    cout << cnt << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

