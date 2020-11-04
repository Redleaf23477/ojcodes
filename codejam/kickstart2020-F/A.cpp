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
        cout << "Case #" << t << ":";
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
LL x;
vector<LL> arr;

void init()
{
    cin >> n >> x;
    arr.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    vector<tuple<LL,int>> que(n);
    for(int i = 0; i < n; i++)
    {
        que[i] = make_tuple((arr[i]+x-1)/x, i);
    }
    sort(que.begin(), que.end());
    for(int i = 0; i < n; i++)
    {
        cout << " " << get<1>(que[i])+1;
    }
    cout << endl;
}

