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
set<tuple<int,int,int>> pq;

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
    for(int i = 2; i < n-1; i++)
    {
        pq.insert(make_tuple((arr[i-1]-arr[i]), arr[i-1], arr[i]));
    }
}

void run()
{
    int ans = (int)1e9;
    if(s.size() <= 2)
    {
        cout << 0 << endl; return;
    }
    // do twice
    if(!pq.empty())
    {
        auto [_, r1, l2] = *pq.begin();
        auto it = s.begin(), jt = s.end(); jt--;
        ans = min(ans, r1-*it + *jt-l2);
//        cerr << "1 => " << var(ans) << endl;
    }
    // do once
    auto it = s.begin(), jt = s.end(); it++, jt--;
    ans = min(ans, (*jt-*it));
//    cerr << "2 => " << var(ans) << endl;
    it = s.begin(), jt = s.end(); jt--, jt--;
    ans = min(ans, (*jt-*it));
//    cerr << "3 => " << var(ans) << endl;

    cout << ans << endl;
}

void debug()
{
    cerr << "set = ";
    for(auto x : s) cerr << x << " ";
    cerr << endl;
    cerr << "pq = ";
    for(auto [len, l, r] : pq) cerr << "(" << len << "," << l << "," << r << ")";
    cerr << endl;
}

void add(int x)
{
    // only element
    if(s.size() <= 2)
    {
        s.insert(x); return;
    }
    auto bk = s.end(); bk--;
    // smallest
    if(x < *s.begin())
    {
        auto it = s.begin(), rt = it; rt++;
        if(rt != bk)
        {
            pq.insert(make_tuple(*it-*rt, *it, *rt));
        }
        s.insert(x);
        return;
    }
    // largest
    if(x > *bk)
    {
        auto it = bk, lt = it; it--;
        if(lt != s.begin())
        {
            pq.insert(make_tuple(*lt-*it, *lt, *it));
        }
        s.insert(x);
        return;
    }
    // middle
    auto it = s.lower_bound(x);
    auto lt = it, rt = it; lt--;
    if(lt != s.begin() && rt != bk)
    {
        pq.erase(make_tuple(*lt-*rt, *lt, *rt));
    }
    if(lt != s.begin())
    {
        pq.insert(make_tuple(*lt-x, *lt, x));
    }
    if(rt != bk)
    {
        pq.insert(make_tuple(x-*rt, x, *rt));
    }
    s.insert(x);
}

void rm(int x)
{
    if(s.size() <= 3)
    {
        s.erase(x); return;
    }
    auto it = s.find(x), ft = s.begin(), bk = s.end(); bk--;
    if(it == ft)
    {
        auto jt = ft, kt = ft;
        jt++, kt++, kt++;
        s.erase(x);
        pq.erase(make_tuple(*jt-*kt, *jt, *kt));
    }
    else if(it == bk)
    {
        auto jt = bk, kt = bk;
        jt--, kt--, kt--;
        s.erase(x);
        pq.erase(make_tuple(*kt-*jt, *kt, *jt));
    }
    else
    {
        auto lt = it, rt = it; lt--, rt++;
        s.erase(x);
        if(lt != ft)
        {
            pq.erase(make_tuple(*lt-x, *lt, x));
        }
        if(rt != bk)
        {
            pq.erase(make_tuple(x-*rt, x, *rt));
        }
        if(lt != ft && rt != bk)
        {
            pq.insert(make_tuple(*lt-*rt, *lt, *rt));
        }
    }
}

void process()
{
    run();
    while(q--)
    {
        int cmd, x; cin >> cmd >> x;
        if(cmd == 1) add(x);
        else rm(x);
        run();
    }
}

