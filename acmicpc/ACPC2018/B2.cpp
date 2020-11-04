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

ifstream fin("baklava.in");
#define cin fin

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

double n;
const double PI = acos(-1);

void init()
{
    cin >> n;
}

void process()
{
    double ans = 0;
    double side2 = 0.25;
    const double theta = PI - 2*PI/n;
    const double phi = 2*PI/n;
    const double area = n * sin(phi) / 4.0 / (1.0-cos(phi));
    for(int iter = 1; iter <= 100000; iter++)
    {
        ans += iter * n * 0.5 * side2 * sin(theta) / area;
        side2 = side2 + side2 - 2*side2*cos(theta);
        side2 /= 4.0;
    }
    cout << fixed << setprecision(5) << ans*10000 << endl;
}

