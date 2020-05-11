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

int n, m;
vector<int> arr;

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
    cin >> n >> m;
    arr.resize(m);
    for(int i = 0; i < m; i++) cin >> arr[i];
}

void process()
{
    int r = 0;
    vector<int> ans(m);
    for(int i = 0; i < m; i++)
    {
        ans[i] = i+1;
        r = max(r, i+arr[i]);
    }
    if(r > n)
    {
        cout << -1 << endl; return;
    }
    r = n;
    bool good = false;
    for(int i = m-1; i >= 0; i--)
    {
        if(ans[i]+arr[i]-1 >= r) 
        {
            good = true;
            break;
        }
        ans[i] = r-arr[i]+1;
        r = ans[i]-1;
    }
    if(good || r == 0)
    {
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
    else cout << -1 << endl;

}

