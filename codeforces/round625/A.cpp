// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

ll cur;

struct P
{
    ll beauty, idx;
};

bool operator < (const P &lhs, const P &rhs)
{
    return lhs.beauty+cur-lhs.idx < rhs.beauty+cur-rhs.idx;
}

ll n;
vector<ll> arr;
vector<ll> dp;

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
    arr.resize(n);
    dp.resize(n, 0);
    for(auto &x : arr) cin >> x;
}

void process()
{
    set<P> s;
    for(cur = 0; cur < n; cur++)
    {
        dp[cur] = arr[cur];
        auto it = s.find((P){arr[cur], cur});
        if(it != s.end())
        {
            dp[cur] += dp[(*it).idx];
            s.erase(it);
        }
        /*
        cerr << var(cur) << var(dp[cur]) << endl;
        */
        s.insert((P){arr[cur], cur});
        /*
        cerr << var(cur) << " : ";
        for(auto x : s) cerr << "(" << x.beauty << "," << x.idx << ")";
        cerr << endl;
        */
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

