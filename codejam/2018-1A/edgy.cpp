//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<double, double> Rect;
#define w first
#define h second

double pw2(double x) { return x*x; }

bool operator < (const Rect &lhs, const Rect &rhs)
{
    return pw2(lhs.w) + pw2(lhs.h) > pw2(rhs.w) + pw2(rhs.h);
}

const double eps = 1e-8;

int n;
double p;
vector<Rect> arr;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> p;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].w >> arr[i].h;
        if(arr[i].h < arr[i].w) swap(arr[i].h, arr[i].w);
    }
    sort(arr.begin(), arr.end());
}

void process()
{
    double sum = 0;
    for(int i = 0; i < n; i++) sum += (arr[i].w+arr[i].h);
    for(int i = 0; i < n; i++)
    {
        if(p/2.0-sum > sqrt(pw2(arr[i].w)+pw2(arr[i].h)))
        {
            sum += sqrt(pw2(arr[i].w) + pw2(arr[i].h));
        }
        else if(p/2.0-sum < arr[i].w) continue;
        else
        {
            cout << fixed << setprecision(8) << p << endl;
            return;
        }
    }
    //cerr << fixed << setprecision(8) << sum*2.0 << endl;
    assert(2.0*sum <= p);
    cout << fixed << setprecision(8) << sum*2.0 << endl;
}

