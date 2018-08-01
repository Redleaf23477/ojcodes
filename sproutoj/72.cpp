//72-happiness function
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

struct Eq
{
    double a, b, c;
    Eq(double x, double y, double z):a(x), b(y), c(z){}
    double cal(double t) { return a*(t-b)*(t-b)+c; }
};

int n;
vector<Eq> eq;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    eq.clear();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double a, b, c; cin >> a >> b >> c;
        eq.emplace_back(a, b, c);
    }
}

double cal(double t)
{
    double mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, eq[i].cal(t));
    return mx;
}

void process()
{
    double low = 0, high = 300, l, r;
    while(high-low > 1e-9)
    {
        l = low+(high-low)/3, r = l+(high-low)/3;
        double lv = cal(l), rv = cal(r);
        if(lv < rv) high = r;
        else low = l;
    }
    cout << fixed << setprecision(5) << cal(low) << endl;
}

