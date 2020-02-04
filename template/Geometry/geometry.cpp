// Computational Geometry Template
// Modified from CP3
#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////
// Basic Funcions & Constants
/////////////////////////////////////////

const double EPS = 1e-9;
const double PI = acos(-1.0);

inline double deg2rad(double d) {
    return d * PI / 180.0;
}

inline double rad2deg(double r) {
    return r * 180.0 / PI;
}

/////////////////////////////////////////
// 0D object : Point
/////////////////////////////////////////

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0):x(_x), y(_y) {}
    // compare first by x, then y
    bool operator < (Point that) const {
        if(fabs(x - that.x) > EPS)
            return x < that.x;
        return this->y < that.y;
    }
    bool operator == (Point that) const {
        return fabs(x - that.x) < EPS && fabs(y - that.y) < EPS; 
    }
};

// euclidean distance
double dist(Point p1, Point p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

// rotate by theta(degrees) CCW w.r.t. (0, 0)
Point rotateByDeg(Point p, double deg) {
    double rad = deg2rad(deg);
    // rotation matrix
    return Point(p.x * cos(rad) - p.y*sin(rad),
            p.x*sin(rad) + p.y*cos(rad));
}

/////////////////////////////////////////
// 1D object : (Infinite) Line
//  in form : ax + by + c = 0
//  Fix b = 0.0 for vertical Line
//  Fix b = 1.0 otherwise
/////////////////////////////////////////

struct Line {
    double a, b, c; 
};

void initLine(Point p1, Point p2, Line &l) {
    if(fabs(p1.x-p2.x) < EPS) {
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    }
    else {
        l.a = -(p1.y-p2.y)/(p1.x-p2.x);
        l.b = 1.0, l.c = -(l.a*p1.x)-p1.y;
    }
}

bool areParallel(Line l1, Line l2) {
    return fabs(l1.a-l2.a) < EPS && fabs(l1.b-l2.b) < EPS;
}

bool areSame(Line l1, Line l2) {
    return areParallel(l1, l2) && fabs(l1.c-l2.c) < EPS;
}

// return whether two Lines have intersection
// if so, store intersection in p
bool areIntersect(Line l1, Line l2, Point &p) {
    if(areParallel(l1, l2)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    // special case when vertical line (b = 0.0)
    // either one of l1, l2 is not vertical since not parallel
    if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

/////////////////////////////////////////
// 1D object : vector
/////////////////////////////////////////

struct Vec {
    double x, y;
    Vec(double _x = 0, double _y = 0):x(_x), y(_y){}
    Vec(Point a, Point b):x(b.x-a.x), y(b.y-a.y) {}
    Vec scale(double s) const {
        return Vec(x*s, y*s);
    }
    double norm2() const {
        return x*x + y*y;
    }
};

// move point by a vector
Point translate(Point p, Vec v) {
    return Point(p.x+v.x, p.y+v.y); 
}

double dot(Vec a, Vec b) {
    return a.x*b.x + a.y*b.y;
}

double cross(Vec a, Vec b) {
    return a.x*b.y - a.y*b.x;
}

// return Euclidean dist from p to inf line(a, b),
// store p's closest point in c
double distToLine(Point p, Point a, Point b, Point &c) {
    Vec ap(a, p), ab(a, b);
    double u = dot(ap, ab) / ab.norm2();
    c = translate(a, ab.scale(u));
    return dist(p, c);
}

// return Euclidean dist from p to line segment (a, b),
// store p's closest point in c
double distToLineSeg(Point p, Point a, Point b, Point &c) {
    Vec ap(a, p), ab(a, b);
    double u = dot(ap, ab) / ab.norm2();
    if(u < 0.0)
        return dist(p, c = a);
    else if(u > 1.0)
        return dist(p, c = b);
    else
        return distToLine(p, a, b, c);
}

// return true if p is on left of line pq
bool ccw(Point p, Point q, Point r) {
    return cross(Vec(p,q), Vec(p,r)) > -EPS;
}

// return true if r is on line(p,q)
bool collinear(Point p, Point q, Point r) {
    return fabs(cross(Vec(p,q), Vec(p,r)) < EPS);
}

// return angle of aob in degree
double angleInDeg(Point a, Point o, Point b) {
    Vec oa(o, a), ob(o, b);
    return acos(dot(oa, ob) / sqrt(oa.norm2() * ob.norm2()));
}

/////////////////////////////////////////
// 1D object : line
//  determined by two points
/////////////////////////////////////////

struct Line2Pt {
    Point p1, p2;
};

// return true if l1, l2 has intersection
bool hasIntersect(Line2Pt l1, Line2Pt l2) {
    return (ccw(l1.p1, l1.p2, l2.p1) != ccw(l1.p1, l1.p2, l2.p2))
        && (ccw(l2.p1, l2.p2, l1.p1) != ccw(l2.p1, l2.p2, l1.p2));
}

/////////////////////////////////////////
// 2D object : Circle related function
/////////////////////////////////////////

// whether p in inside circle(c, r)
int pointInsideCircle(Point p, Point c, double r) {
    const int INSIDE = 0, BORDER = 1, OUTSIDE = 2;
    double dx = p.x-c.x, dy = p.y-c.y;
    double d2 = dx*dx + dy*dy, r2 = r*r;
    return fabs(d2-r2) < EPS? BORDER : d2 < r2? INSIDE : OUTSIDE;
}

/////////////////////////////////////////
// 2D object : Triangle related function
/////////////////////////////////////////

// given len of 3 sides, cal area of triangle
double triArea(double a, double b, double c) {
    double sp = (a+b+c)/2.0;
    return sqrt(sp*(sp-a) * (sp-b) * (sp-c));
}

// given len of 3 sides
// return radis of incircle
double rInCircle(double a, double b, double c) {
    double sp = (a+b+c)/2.0;
    return triArea(a, b, c)/sp;
}

// given 3 vertices
// return radis of incircle
double rInCircle(Point a, Point b, Point c) {
    return rInCircle(dist(a, b), dist(a, c), dist(b, c));
}

/////////////////////////////////////////
// Unit Test
/////////////////////////////////////////

void testRotateByDeg()
{
    double a, b, deg; cin >> a >> b >> deg;
    Point p1(a, b), p2 = rotateByDeg(p1, deg);
    cout << "(" << p2.x << "," << p2.y << ")" << endl;
}

void testInitLine()
{
    Point a, b;
    Line l;
    cin >> a.x >> a.y >> b.x >> b.y;
    initLine(a, b, l);
    cout << l.a << "x + " << l.b << "y + " << l.c << " = 0" << endl;
}

void testTranslate()
{
    Point p, t;
    Vec v;
    cin >> p.x >> p.y >> v.x >> v.y;
    t = translate(p, v);
    cout << t.x << " " << t.y << endl;
}

void testInCircle()
{
    Point p, c; double r;
    cin >> c.x >> c.y >> r;
    while(cin >> p.x >> p.y)
        cout << pointInsideCircle(p, c, r) << endl;
}

int main()
{
    cout << fixed << setprecision(20);
    testInCircle();
    return 0;
}

