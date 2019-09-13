/*
 * DP : convex hull trick (maintain min of upper convex hull)
 *
 * Tested using : https://atcoder.jp/contests/dp/tasks/dp_z
 *
 * Time Complexity: same as maintaining convex hull
 * 
 */

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 200005;

template<typename Ty = long long int>
class Linear
{
private:
    Ty a, b;
public:
    Linear(Ty a, Ty b):a(a), b(b) {}
    Ty operator()(Ty x) { return a*x+b; }
    // get x of intersection of two lines (fraction)
    tuple<Ty, Ty> inter(Linear &that)
    {
        ll up = that.b-this->b;
        ll down = this->a-that.a;
        if(down < 0) up *= -1, down *= -1;
        return make_tuple(up, down);
    }
};

template<typename Ty = long long int>
class ConvexHull
{
private:
    using L = Linear<Ty>;
    vector<L> hull;
public:
    void push_back(L h)
    {
        while(hull.size() >= 2)
        {
            auto &f = hull.end()[-2];
            auto &g = hull.end()[-1];  // back
            // x of inter(h,f) <= x of inter(f,g)
            Ty a, b, c, d;
            tie(a, b) = h.inter(f);
            tie(c, d) = f.inter(g);
            if(a*d <= b*c) hull.pop_back();
            else break;
        }
        hull.push_back(h);
    }
    Ty operator() (Ty x)
    {
        static int idx = 0;
        if(idx >= hull.size()) 
            idx = max(0, (int)hull.size()-2);
        while(idx+1 < hull.size())
        {
            if(hull[idx+1](x) <= hull[idx](x)) idx++;
            else break;
        }
        return hull[idx](x);
    }
};

ll n, m;
ll sum[N];
ll dp[N];

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
    for(int i = 1; i <= n; i++) 
    {
        cin >> sum[i]; sum[i] += sum[i-1];
    }
}

void process()
{
    ConvexHull<ll> hull;
    dp[1] = sum[1]*sum[1]+m;
    hull.push_back(Linear<ll>(-2*sum[1], dp[1]+sum[1]*sum[1]));
    for(int i = 2; i <= n; i++)
    {
        dp[i] = hull(sum[i]) + sum[i]*sum[i] + m;
        Linear<ll> tmp(-2*sum[i], dp[i]+sum[i]*sum[i]);
        hull.push_back(tmp);
    }
    cout << dp[n] << endl;
}

/*

// O(n^2)
dp[i] = min(dp[j] + (sum[j+1] + ... + sum[i])^2) + m;

dp[i] = min(dp[j] + (sum[i] - sum[j])^2) + m;

dp[i] = min(dp[j] + sum[i]^2 - 2*sum[i]*sum[j] + sum[j]^2) + m

dp[i] = min(dp[j] - 2*sum[i]*sum[j] + sum[j]^2) + m + sum[i]^2

//      a         x     +     b
// (-2*sum[j]) (sum[i]) + (dp[j]+sum[j]^2)

*/
