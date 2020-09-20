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
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, x;
vector<int> arr;

void init()
{
}

bool case1()
{
    bool same = true;
    for(auto a : arr)
        if(a != x) same = false;
    return same;
}

bool case2()
{
    int diff = 0;
    for(auto a : arr) diff += a-x;
    return diff == 0;
}

bool case3()
{
    for(auto a : arr) if(a == x) return true;
    return false;
}

void process()
{
    cin >> n >> x;
    arr.resize(n); for(auto &a : arr) cin >> a;

    if(case1()) cout << 0 << endl;
    else if(case2()) cout << 1 << endl;
    else if(case3()) cout << 1 << endl;
    else cout << 2 << endl;
}

