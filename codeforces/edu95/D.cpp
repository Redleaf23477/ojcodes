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
set<int> s;
priority_queue<tuple<int,int,int>> pq;

void init()
{
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++) pq.emplace(arr[i]-arr[i-1], arr[i-1], arr[i]);
}

void run()
{
    while(!pq.empty())
    {
        auto [len, l, r] = pq.top();
        if(s.count(l) == 0) { pq.pop(); continue; }
        if(s.count(r) == 0) { pq.pop(); continue; }
        auto lt = s.find(l), rt = s.find(r); lt++;
        if(lt != rt) { pq.pop(); continue; }
        auto ft = s.begin(), bk = s.end(); bk--;
        cout << *bk-*ft-len << endl;
        return;
    }
    cout << 0 << endl;
}

void add(int x)
{
    s.insert(x);
    auto it = s.find(x);
    if(it != s.begin())
    {
        auto lt = it; lt--;
        pq.emplace(x-*lt, *lt, x);
    }
    auto rt = it; rt++;
    if(rt != s.end())
    {
        pq.emplace(*rt-x, x, *rt);
    }
}

void rm(int x)
{
    auto it = s.find(x), lt = it, rt = it;
    if(lt != s.begin())
    {
        lt--; rt++;
        if(rt != s.end())
            pq.emplace(*rt-*lt, *lt, *rt);
    }
    s.erase(x);
}

void debug()
{
    priority_queue<tuple<int,int,int>> tmp = pq;
    while(!tmp.empty())
    {
        auto [len, l, r] = tmp.top(); tmp.pop();
        cerr << "(" << len << "," << l << "," << r << ")";
    }
    cerr << endl;
}

void process()
{
    run();
//    debug();
    while(q--)
    {
        int cmd, x; cin >> cmd >> x;
        if(cmd == 1) add(x);
        else rm(x);
        run();
//        debug();
    }
}

