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

int n;
vector<int> arr, brr;

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
    brr.resize(n);
    for(auto &x : arr) cin >> x;
    for(auto &x : brr) cin >> x;
}

void process()
{
    bool pos = false, neg = false;
    bool good = true;
    for(int i = 0; i < n && good; i++)
    {
        if(arr[i] < brr[i]) good &= pos;
        if(arr[i] > brr[i]) good &= neg;
        if(arr[i] == 1) pos = true;
        if(arr[i] == -1) neg = true;
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}

