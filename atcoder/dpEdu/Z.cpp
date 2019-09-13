//
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
            // x of inter(h, f) <= x of inter(f, g)
            Ty a, b, c, d;
            tie(a, b) = h.inter(f);
            tie(c, d) = f.inter(g);
            // inter_hf.first / inter_hf.second <= inter_fg.first / inter_fg.second
            if((__int128)a*d <= (__int128)b*c) hull.pop_back();
            else break;
        }
        hull.push_back(h);
    }
    Ty operator() (Ty x)
    {
        static int idx = 0;
        // test: hull.size()-1?
        if(idx >= hull.size()) idx = max(0, (int)hull.size()-2);
        while(idx+1 < hull.size())
        {
            if(hull[idx+1](x) <= hull[idx](x)) idx++;
            else break;
        }
        return hull[idx](x);
    }
};

int n;
ll c;
ll h[N];
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
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> h[i];
}

/*
ll getVal(Linear &l, ll x)
{
    return l.a*x+l.b;
}

pair<ll,ll> inter(Linear &g, Linear &h)
{
    ll up = h.b-g.b;
    ll down = g.a-h.a;
    if(down < 0) up *= -1, down *= -1;
    return make_pair(up, down);
}

ll getMin(vector<Linear> &hull, ll x)
{
    static int idx = 0;
    // test: hull.size()-1?
    if(idx >= hull.size()) idx = max(0, (int)hull.size()-2);
    while(idx+1 < hull.size())
    {
        if(getVal(hull[idx+1], x) <= getVal(hull[idx], x)) idx++;
        else break;
    }
    return getVal(hull[idx], x);
}

void validateHull(vector<Linear> &hull, Linear &h)
{
    while(hull.size() >= 2)
    {
        auto &f = hull.end()[-2];
        auto &g = hull.end()[-1];  // back
        // x of inter(h, f) <= x of inter(f, g)
        auto inter_hf = inter(h, f);
        auto inter_fg = inter(f, g);
        // inter_hf.first / inter_hf.second <= inter_fg.first / inter_fg.second
        if((__int128)inter_hf.first*inter_fg.second <= (__int128)inter_fg.first*inter_hf.second)
            hull.pop_back();
        else
            break;
    }
    hull.push_back(h);
}
*/

void process()
{
    ConvexHull<ll> hull;
    dp[0] = 0;
    hull.push_back(Linear<ll>(-2*h[0], dp[0]+h[0]*h[0]));
    for(int i = 1; i < n; i++)
    {
        dp[i] = hull(h[i]) + h[i]*h[i] + c;
        Linear<ll> tmp(-2*h[i], dp[i] + h[i]*h[i]);
        hull.push_back(tmp);
    }
    cout << dp[n-1] << endl;
    /*
    vector<Linear> hull;
    dp[0] = 0;
    hull.emplace_back(-2*h[0], dp[0]+h[0]*h[0]);
    for(int i = 1; i < n; i++)
    {
        dp[i] = getMin(hull, h[i]) + h[i]*h[i] + c;
        Linear tmp(-2*h[i], dp[i]+h[i]*h[i]);
        // validate convex hull
        validateHull(hull, tmp);
    }
    cout << dp[n-1] << endl;
    */
}

