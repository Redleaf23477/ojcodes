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

int n, l;
vector<double> pos;
vector<double> car1, car2;

void init()
{
    cin >> n >> l;
    pos.clear();
    pos.emplace_back(0);
    for(int i = 0, p; i < n; i++)
    {
        cin >> p; pos.emplace_back(p);
    }
    pos.emplace_back(l);
    car1.assign(n+2, 0), car2.assign(n+2, 0);
    // car 1
    double v = 1, x = 0, t = 0;
    car1[0] = 0;
    for(int i = 1; i < n+2; i++)
    {
        t += (pos[i]-x)/v;
        car1[i] = t;
        x = pos[i];
        v += 1;
    }
    // car 2
    v = 1, x = l, t = 0;
    car2[n+1] = 0;
    for(int i = n; i >= 0; i--)
    {
        t += (x-pos[i])/v;
        car2[i] = t;
        x = pos[i];
        v += 1;
    }
    reverse(car2.begin(), car2.end());

    n = n+2;

    /*
    cerr << "car1 = ";
    for(int i = 0; i < n; i++) cerr << car1[i] << " ";
    cerr << endl;
    cerr << "car2 = ";
    for(int i = 0; i < n; i++) cerr << car2[i] << " ";
    cerr << endl;
    */
}

bool ok(double t)
{
    int idx1 = upper_bound(car1.begin(), car1.end(), t) - car1.begin() - 1;
    int idx2 = upper_bound(car2.begin(), car2.end(), t) - car2.begin() - 1;
    if(idx1 + idx2 + 2 > n) return true;
    else if(idx1 + idx2 + 2 < n) return false;
    else
    {
        int v1 = 1+idx1, v2 = 1+idx2;
        double t1 = car1[idx1], t2 = car2[idx2];
        double tt1 = t - t1, tt2 = t - t2;
        double dist = pos[n-idx2-1] - pos[idx1];
        if(tt1 * v1 + tt2 * v2 >= dist) return true;
        else return false;
    }
}

void process()
{
    double low = 0, high = l, mid, ans = l/2.0;
    for(int iter = 0; iter < 60; iter++)
    {
        mid = (low+high)/2.0;
        if(ok(mid)) ans = mid, high = mid;
        else low = mid;
    }
    cout << fixed << setprecision(8) << ans << endl;
}
