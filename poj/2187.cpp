//
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Point;
#define x first
#define y second

const int N = 50004;
int n;
Point arr[N];
vector<Point> convex;

bool cmp_xy(const Point &lhs, const Point &rhs)
{
    return lhs.x < rhs.x || (lhs.x==rhs.x && lhs.y < rhs.y);
}

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

Point operator - (const Point lhs, const Point rhs)
{
    return make_pair(lhs.x-rhs.x, lhs.y-rhs.y);
}

ll cross(const Point lhs, const Point rhs)
{
    return lhs.x*rhs.y - lhs.y*rhs.x;
}

ll dist2(const Point a, const Point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void getConvex()
{
    sort(arr, arr+n, cmp_xy);
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        while(k > 1 && cross(convex[k-1]-convex[k-2], arr[i]-convex[k-1]) <= 0) k--, convex.pop_back();
        k++, convex.push_back(arr[i]);
    }
    int s = k;
    for(int i = n-2; i >= 0; i--)
    {
        while(s > k && cross(convex[s-1]-convex[s-2], arr[i]-convex[s-1]) <= 0) s--, convex.pop_back();
        s++, convex.push_back(arr[i]);
    }
    if(convex.size()) s--, convex.pop_back();
}

ll maxDist()
{
    ll mx = 0, csz = convex.size();
    for(int i = 0, j = 0; i < csz; i++)
    {
        while(true)
        {
            ll older = dist2(arr[i], arr[j]);
            ll newer = dist2(arr[i], arr[(j+1)%csz]);
            if(newer >= older) mx = max(mx, newer), j = (j+1)%csz;
            else break;
        }
    }
    return mx;
}

void init()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld %lld", &arr[i].x, &arr[i].y);
    getConvex();
}

void process()
{
    printf("%lld\n", maxDist());
}

