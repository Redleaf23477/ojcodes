/*
 * Point, Convex Hull, Rotating Clapier
 *
 * Tested : 2017-2018 ICPC Southwestern European pK - Blowing Candles
 *
*/

const double eps = 5e-8;
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator+(Point b)const{
        return Point(x+b.x,y+b.y); 
    }
    Point operator-(Point b)const{
        return Point(x-b.x,y-b.y); 
    }
    Point operator*(double b)const{
        return Point(x*b,y*b); 
    }
    Point operator/(double b)const{
        return Point(x/b,y/b); 
    }
    bool operator==(Point b)const{
        return (fabs(x-b.x)<=eps&&fabs(y-b.y)<=eps);
    }
    double dot(Point b)const{
        return x*b.x+y*b.y; 
    }
    double cross(Point b)const{
        return x*b.y-y*b.x; 
    }
    Point normal()const{  
        return Point(-y,x); 
    } // 求法向量
    double abs2()const{
        return dot(*this); 
    } // 向量長度的平方
    double rad(const Point b)const{ 
        return fabs(atan2(fabs(cross(b)),dot(b))); 
    } // 兩向量的弧度
};

struct ConvexHull
{
    static bool cmp(const Point &lhs, const Point &rhs)
    {
        if(lhs.x == rhs.x) return lhs.y < rhs.y;
        else return lhs.x < rhs.x;
    }
    vector<Point> buildHull(vector<Point> &pts)
    {
        vector<Point> hull;
        sort(pts.begin(), pts.end(), cmp);
        // lower hull
        for(auto &p : pts)
        {
            while(hull.size() > 1)
            {
                auto b = hull.end()[-1]; // back
                auto bb = hull.end()[-2];
                if((p-bb).cross(p-b) <= 0) hull.pop_back();
                else break;
            }
            hull.push_back(p);
        }
        // upper hull
        size_t upsz = hull.size();
        for(int i = pts.size()-2; i >= 0; i--)
        {
            auto p = pts[i];
            while(hull.size() > upsz)
            {
                auto b = hull.end()[-1]; // back
                auto bb = hull.end()[-2];
                if((p-bb).cross(p-b) <= 0) hull.pop_back();
                else break;
            }
            hull.push_back(p);
        }
        hull.pop_back();
        return hull;
    }
    double hullMinWidth(vector<Point> &pts, double R)
    {
        auto hull = buildHull(pts);
        int n = hull.size();
        double ans = R*2;
        for(int i = 0, j = 1; i < n; i++)
        {
            while((hull[(i+1)%n]-hull[i]).cross(hull[j]-hull[i]) < (hull[(i+1)%n]-hull[i]).cross(hull[(j+1)%n]-hull[i])) j = (j+1)%n;
            auto bot = hull[(i+1)%n]-hull[i];
            ans = min(ans, bot.cross(hull[j]-hull[i])/sqrt(bot.dot(bot)));
        }
        return ans;
    }
};
