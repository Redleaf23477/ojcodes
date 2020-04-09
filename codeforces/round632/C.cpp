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

ll n;
vector<ll> arr, pre;

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
    cin >> n;
    arr.resize(n+1, 0), pre.resize(n+1, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i+1];
        pre[i+1] = pre[i] + arr[i+1];
    }
}

void process()
{
    ll bad = 0;
    int badl = 0;
    map<ll,int> mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(mp.count(pre[i])) 
        {
//            cerr << var(i) << var(mp[pre[i]]) << endl;
            badl = max(badl, mp[pre[i]]+1);
        }
        if(mp.count(pre[i]) == 0) mp[pre[i]] = i;
        mp[pre[i]] = i;
//        cerr << var(i) << var(badl) << endl;
        bad += badl;
    }
//    cerr << var(bad) << endl;
    cout << n*(n+1)/2 - bad << endl;
}

