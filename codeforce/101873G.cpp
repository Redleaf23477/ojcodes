//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> Point;
#define x first
#define y second

ll cross(const Point &a, const Point &b)
{
    return a.x*b.y - a.y*b.x;
}

/* Do not sort
int quad(const Point &p)
{
    if(p.x == 0 && p.y == 0) return 0;
    if(p.x > 0 && p.y >= 0) return 1;
    if(p.x <= 0 && p.y > 0) return 2;
    if(p.x < 0 && p.y <= 0) return 3;
    if(p.x >= 0 && p.y < 0) return 4;
}

ll dist2(const Point &p)
{
    return p.x*p.x + p.y*p.y;
}

bool cmp(const Point &a, const Point &b)
{
    int qa = quad(a), qb = quad(b);
    if(qa != qb) return qa < qb;
    ll crs = cross(a, b);
    return crs > 0 || (crs == 0 && dist2(a) > dist2(b));
}
*/

const int N = 100005;

int n;
Point pt[N];

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
    for(int i = 0; i < n; i++)
    {
        cin >> pt[i].x >> pt[i].y;
    }
}

ll cntArea()
{
    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        tot += cross(pt[i], pt[j]);
    }
    return abs(tot/2);
}

ll cntBorder()
{
    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        tot += __gcd(abs(pt[i].x-pt[j].x), abs(pt[i].y-pt[j].y));
    }
    return tot;
}

void process()
{
    // pick's theorem: A = I + R/2 - 1
    // I = A - R/2 + 1
    ll area = cntArea();
    ll border = cntBorder();
//    cout << "area " << area << endl;
//    cout << "border " << border << endl;
    cout << area-border/2+1 << endl;
}

