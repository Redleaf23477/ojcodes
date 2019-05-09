//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const long double EPS = 1e-16;
const long double PI = acos(-1);

/////////////////////////////

typedef pair<long double, long double> P;
#define x first
#define y second

P operator - (const P lhs, const P rhs)
{
    return make_pair(lhs.x-rhs.x, lhs.y-rhs.y);
}

long double cross(const P lhs, const P rhs)
{
    return lhs.x*rhs.y - lhs.y*rhs.x;
}

bool cmp_xy(const P &lhs, const P &rhs)
{
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

vector<P> getConvexHull(vector<P> &pts)
{
    vector<P> hull;
    sort(pts.begin(), pts.end(), cmp_xy);

    int hsz = 0;
    for(size_t i = 0; i < pts.size(); i++)
    {
        while(hsz > 1 && cross(hull[hsz-1]-hull[hsz-2], pts[i]-hull[hsz-1]) <= 0) hsz--, hull.pop_back();
        hsz++, hull.push_back(pts[i]);
    }
    int lower = hsz;
    for(int i = pts.size()-2; i >= 0; i--)
    {
        while(hsz > lower && cross(hull[hsz-1]-hull[hsz-2], pts[i]-hull[hsz-1]) <= 0) hsz--, hull.pop_back();
        hsz++, hull.push_back(pts[i]);
    }
    if(hull.size()) hull.pop_back();

    return hull;
}

long double calArea(vector<P> &hull)
{
    long double sum = 0;

    for(size_t i = 1; i < hull.size(); i++)
    {
        sum += cross(hull[i-1]-hull[0], hull[i]-hull[0]);
    }

    return sum/2;
}

/////////////////////////////

typedef vector<vector<long double>> Mat;

Mat mul(const Mat &lhs, const Mat &rhs)
{
    Mat res;
    res.resize(lhs.size());
    for(auto &r:res) r.resize(rhs[0].size(), 0);

    for(size_t i = 0; i < res.size(); i++)
        for(size_t j = 0; j < res[i].size(); j++)
            for(size_t k = 0; k < rhs.size(); k++)
                res[i][j] += lhs[i][k] * rhs[k][j];

    return res;
}

/////////////////////////////

long double getArea(long double x, long double y, long double z)
{
    Mat rot_x, rot_y, rot_z;
    rot_x.resize(3); for(auto &r:rot_x) r.resize(3, 0);
    rot_y.resize(3); for(auto &r:rot_y) r.resize(3, 0);
    rot_z.resize(3); for(auto &r:rot_z) r.resize(3, 0);

    rot_x[0][0] = 1;
    rot_x[1][1] = cos(x), rot_x[1][2] = -sin(x);
    rot_x[2][1] = sin(x), rot_x[2][2] = cos(x);

    rot_y[0][0] = cos(y), rot_y[0][2] = sin(y);
    rot_y[1][1] = 1;
    rot_y[2][0] = -sin(y), rot_y[2][2] = cos(y);

    rot_z[0][0] = cos(z), rot_z[0][1] = -sin(z);
    rot_z[1][0] = sin(z), rot_z[1][1] = cos(z);
    rot_z[2][2] = 1;

    Mat pts;
    pts.resize(3); for(auto &r:pts) r.resize(8);
    for(size_t i = 0; i < 8; i++) pts[0][i] = (i%8 < 4? 0.5 : -0.5);
    for(size_t i = 0; i < 8; i++) pts[1][i] = (i%4 < 2? 0.5 : -0.5);
    for(size_t i = 0; i < 8; i++) pts[2][i] = (i%2 < 1? 0.5 : -0.5);

    Mat rot = mul(rot_x, rot_y);
    rot = mul(rot_z, rot);
    Mat newPtsMat = mul(rot, pts);

    vector<P> newPts;
    for(int i = 0; i < 8; i++) newPts.emplace_back(newPtsMat[0][i], newPtsMat[2][i]);
    
    vector<P> hull = getConvexHull(newPts);
    return calArea(hull);
}

void report(long double x, long double y, long double z)
{
    Mat rot_x, rot_y, rot_z;
    rot_x.resize(3); for(auto &r:rot_x) r.resize(3, 0);
    rot_y.resize(3); for(auto &r:rot_y) r.resize(3, 0);
    rot_z.resize(3); for(auto &r:rot_z) r.resize(3, 0);

    rot_x[0][0] = 1;
    rot_x[1][1] = cos(x), rot_x[1][2] = -sin(x);
    rot_x[2][1] = sin(x), rot_x[2][2] = cos(x);

    rot_y[0][0] = cos(y), rot_y[0][2] = sin(y);
    rot_y[1][1] = 1;
    rot_y[2][0] = -sin(y), rot_y[2][2] = cos(y);

    rot_z[0][0] = cos(z), rot_z[0][1] = -sin(z);
    rot_z[1][0] = sin(z), rot_z[1][1] = cos(z);
    rot_z[2][2] = 1;

    Mat pts;
    pts.resize(3); for(auto &r:pts) r.resize(3);
    pts[0][0] = pts[1][1] = pts[2][2] = 0.5;

    Mat rot = mul(rot_x, rot_y);
    rot = mul(rot_z, rot);
    Mat newPtsMat = mul(rot, pts);

    for(int i = 0; i < 3; i++) 
        cout << fixed << setprecision(9) << newPtsMat[0][i] << " " << newPtsMat[1][i] << " " << newPtsMat[2][i] << endl;
//    cout << ".." << x/PI*180 << " " << y/PI*180 << " " << z/PI*180 << endl;
}

/////////////////////////////

long double A;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ":" << endl;
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    double tmp; cin >> tmp;
    A = tmp;
}

void process()
{
    long double x, y, z;
    bool small;

//    if(A > sqrt(2)+EPS) x = 0, y = PI/4, z = 0, small = false;
//    else x = 0, y = 0, z = 0, small = true;

    x = 0, y = PI/4, z = 0, small = false;

    long double low = 0, high = asin(2.0*sqrt(2)/3), area, phi;
    int i = 0;
    for(i = 0; i < 300; i++)
    {
        phi = (low+high)/2;
        area = getArea(phi, y, z);
        if(area > A+EPS) high = phi-EPS;
        else if(area < A-EPS) low = phi+EPS;
        else break;
//        cout << "xxx" << phi << endl;
    }

    report(phi, y, z);
//    cout << ".." << i << " " << area << endl;
    assert(fabs(area-A) < 0.000001);
}

