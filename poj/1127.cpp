//
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

class DisjointSet
{
private:
    static const int N = 100;
    int n;
    int pa[N];
    int findrt(int x)
    {
        if(x == pa[x]) return x;
        else return pa[x] = findrt(pa[x]);
    }

public:
    void init(int num)
    {
        n = num;
        for(int i = 0; i <= n; i++) pa[i] = i;
    }
    bool same(int x, int y) { return findrt(x) == findrt(y); }
    void uni(int x, int y) { pa[findrt(x)] = findrt(y); }
};

static const double eps = 1e-7;
struct Point
{
    double x, y;
};

Point operator - (Point lhs, Point rhs) { lhs.x -= rhs.x, lhs.y -= rhs.y; return lhs; }
double operator ^ (const Point lhs, const Point rhs) { return lhs.x*rhs.y - lhs.y*rhs.x; }
double operator * (const Point lhs, const Point rhs) { return lhs.x*rhs.y + lhs.y*rhs.y; }

int ccw(Point a, Point b, Point c)
{
    // whether (a,b) to (a,c) is ccw
    // 1  : ccw
    // 0  : a, b, c, on same line
    // -1 : not cw
    double crs = (b-a) ^ (c-a);
    if(crs > eps) return 1;
    else if(crs < -eps) return -1;
    else return 0;
}

bool onSeg(Point p, Point a, Point b)
{
    // whether p is between a, b
    bool x = min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x);
    bool y = min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    return x && y;
}

bool intersect(Point a, Point b, Point x, Point y)
{
    // whether (a,b) intersect (x,y)
    int abx = ccw(a, b, x);
    int aby = ccw(a, b, y);
    int xya = ccw(x, y, a);
    int xyb = ccw(x, y, b);

    if(abx*aby < 0 && xya*xyb < 0) return true;
    else if(abx == 0) return onSeg(x, a, b);
    else if(aby == 0) return onSeg(y, a, b);
    else if(xya == 0) return onSeg(a, x, y);
    else if(xyb == 0) return onSeg(b, x, y);
    return false;
}

struct Seg
{
    Point a, b;
};

bool intersect(Seg lhs, Seg rhs)
{
    return intersect(lhs.a, lhs.b, rhs.a, rhs.b);
}

const int N = 100;
ll sn;
Seg seg[N];
DisjointSet ds;

void init();
void process();

int main()
{
    while(scanf("%lld", &sn) && sn)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    for(int i = 1; i <= sn; i++)
    {
        scanf("%lf %lf %lf %lf", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
    }
    ds.init(sn);
    for(int i = 1; i <= sn; i++)
        for(int j = 1; j <= sn; j++)
        {
            if(i == j) continue;
            if(intersect(seg[i], seg[j])) ds.uni(i, j);
        }
}

void process()
{
    ll i, j;
    while(scanf("%lld %lld", &i, &j) && i && j)
    {
        if(ds.same(i, j)) printf("CONNECTED\n");
        else printf("NOT CONNECTED\n");
    }
}

