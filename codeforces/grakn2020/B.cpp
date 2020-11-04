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

int n, k;
set<int> s;

void init()
{
    cin >> n >> k;
    s.clear();
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s.insert(x);
    }
}

void process()
{
    int m = s.size();
    if(k == 1)
    {
        if(m == 1) cout << 1 << endl;
        else cout << -1 << endl;
    }
    else
    {
        cout << 1 + max(0, (m-k + k-2)/(k-1)) << endl;
    }
}

