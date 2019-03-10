//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

struct Point
{
    ll x, y;
    Point(ll x, ll y):x(x), y(y){}
    Point(const Point &pt):x(pt.x), y(pt.y){}
    Point():x(0), y(0){}
};

bool cmp_x(const Point &lhs, const Point &rhs)
{
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}
Point operator + (const Point lhs, const Point rhs)
{
    return Point(lhs.x+rhs.x, lhs.y+rhs.y);
}
Point operator - (const Point lhs, const Point rhs)
{
    return Point(lhs.x-rhs.x, lhs.y-rhs.y);
}
ll operator * (const Point lhs, const Point rhs)   // dot
{
    return lhs.x*rhs.x + lhs.y*rhs.y;
}
ll operator ^ (const Point lhs, const Point rhs)   // det
{
    return lhs.x*rhs.y - lhs.y*rhs.x;
}
bool operator == (const Point lhs, const Point rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
ll turn (Point vec0, Point vec1)
{
    ll res = vec0 ^ vec1;
    if(res > 0) return 1;        // CCW
    else if(res == 0) return 0;  // collinear
    else return -1;              // CW
}

/////////////////////////////

int n;
vector<Point> pt;
vector<Point> convex;

void init();
void process();

int32_t main()
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
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pt.emplace_back(x, y);
    }
    sort(pt.begin(), pt.end(), cmp_x);
    n = unique(pt.begin(), pt.end()) - pt.begin();
    pt.resize(n);
}

/*
void getConvex(){//凸包
    vector<Point> &s = pt;
    vector<Point> &p = convex;
    sort(s.begin(),s.end(), cmp_x);
    p.resize(s.size()+1);
    int m=0;
    for(size_t i=0;i<s.size();++i){
        while(m>=2&&((p[m-1]-p[m-2])^(s[i]-p[m-2]))<=0)--m;
        p[m++]=s[i];
    }
    for(int i=s.size()-2,t=m+1;i>=0;--i){
        while(m>=t&&((p[m-1]-p[m-2])^(s[i]-p[m-2]))<=0)--m;
        p[m++]=s[i];
    }
    if(s.size()>1)--m;
    p.resize(m);
}
*/

void getConvex()
{
    // pt is already sorted
    if(n <= 3) { convex = pt; return; }

    int k = 0, t;
    // lower convex hull
    for(int i = 0; i < n; i++)
    {
        while(k > 1 && turn(convex[k-1]-convex[k-2], pt[i]-convex[k-1]) <= 0) k--, convex.pop_back();
        convex.push_back(pt[i]), k++;
    }
    // upper convex hull
    t = k;
    for(int i = n-2; i >= 0; i--)
    {
        while(t > k && turn(convex[t-1]-convex[t-2], pt[i]-convex[t-1]) <= 0) t--, convex.pop_back();
        convex.push_back(pt[i]), t++;
    }
    if(convex.size()) convex.pop_back(), t--;

//    for(auto c : convex) cout << c.x << " " << c.y << endl;
}

/* fuck.........   for each a, b, c should stop at biggest triangle
double maxTriangle()
{
    if(convex.size() <= 2) return 0;
    ll mxArea = 0;
    int csz = convex.size();
    for(int a = 0; a < csz; a++)
    {
        for(int b = (a+1)%csz, c = (b+1)%csz; b != a; b = (b+1)%csz)
        {
            ll tmpmx = 0;
            while(c != a)
            {
                ll newer = llabs((convex[c]-convex[a])^(convex[b]-convex[a]));
                if(newer > tmpmx) mxArea = max(mxArea, newer), tmpmx= max(tmpmx, newer), c = (c+1)%csz;
                else { c = (c-1+csz)%csz; break; }
            }
            mxArea = max(tmpmx, mxArea);
        }
    }
    return (double)mxArea/2.0;
}
*/

double maxTriangle()
{
    if(convex.size() <= 2) return 0;
    ll mxArea = 0;
    int csz = convex.size();
    for(int a = 0; a < csz; a++)
    {
        for(int b = (a+1)%csz, c = b; b != a; b = (b+1)%csz)
        {
            while(c != a)
            {
                ll older = llabs((convex[c]-convex[a])^(convex[b]-convex[a]));
                ll newer = llabs((convex[(c+1)%csz]-convex[a])^(convex[b]-convex[a]));
                if(newer > older) mxArea = max(mxArea, newer), c = (c+1)%csz;
                else break;
            }
        }
    }
    return (double)mxArea/2.0;
}

/*
double maxTriangle()
{
    int m = convex.size();
    for(int i = 0; i < m; i++) convex.push_back(convex[i]);
    ll mx = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = i+1, k = j; j < i+m; j++)
        {
            while(k < i+m)
            {
                ll older = llabs((convex[j]-convex[i])^(convex[k]-convex[i]));
                ll newer = llabs((convex[j]-convex[i])^(convex[k+1]-convex[i]));
                if(newer > older) mx = max(mx, newer), k++;
                else break;
            }
        }
    }
    return (double)mx/2.0;
}
*/

void process()
{
    getConvex();
    cout << fixed << setprecision(9) << maxTriangle() << endl;
}

