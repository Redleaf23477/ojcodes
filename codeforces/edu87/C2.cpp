// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using LL = long long int;
using Pt = pair<double,double>;

const double PI = acos(-1);
const double INF = 1e9;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
}

Pt rot(Pt p, double t)
{
    double x = p.first, y = p.second;
    return make_pair(
            x*cos(t) - y*sin(t), 
            x*sin(t) + y*cos(t)
            );
}

void process()
{
    int n; cin >> n; n *= 2;
    double theta = 2.0*PI/n;
    double rot_theta = 0.25*theta;
    vector<Pt> pt(n); 
    pt[0] = rot(Pt(0.5/sin(theta/2.0), 0), rot_theta);
    for(int i = 1; i < n; i++) pt[i] = rot(pt[i-1], theta);
    double u = -INF, d = INF, l = INF, r = -INF;
    for(int i = 0; i < n; i++)
    {
        double x = pt[i].first, y = pt[i].second;
        u = max(u, y), d = min(d, y);
        l = min(l, x), r = max(r, x);
    }
    cout << fixed << setprecision(9) << max(r-l, u-d) << endl;
}
