// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;
using P = pair<ll,ll>;
#define x first
#define y second

bool center;
P hit;
P seg1, seg2;

ll A, B;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T >> A >> B;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

bool test(ll x, ll y)
{
    cout << x << " " << y << endl;
//    cerr << "ME: " << x << " " << y << endl;
    string str; cin >> str;
//    cerr << "JUDGE: " << str << endl;
    if(str == "CENTER")
    {
        center = 1;
        return true;
    }
    else if(str == "HIT") return true;
    else return false;
}

void init()
{
    center = false;
}

void getHit()
{
    ll len = 2*1e9 / 4;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            bool res = test(-1e9 + i*len, -1e9 + j*len);
            if(center == 1) return;
            if(res == true)
            {
                hit = P(i*len, j*len);
                return;
            }
        }
    }
}

void getSeg1()
{
    // seg1 : -
    ll low = -1e9, high = hit.x, mid;
    for(int iter = 0; iter < 50; iter++)
    {
        if(high-low <= 0) break;
        mid = (low+high)/2;
        if(test(mid, hit.y) == true)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        if(center == 1) return;
    }
    seg1.x = low;
    low = hit.x, high = 1e9;
    for(int iter = 0; iter < 50; iter++)
    {
        if(high-low <= 0) break;
        mid = (low+high)/2;
        if(test(mid, hit.y) == false)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        if(center == 1) return;
    }
    seg1.y = low;
}

void getSeg2()
{
    // seg1 : -
//    cerr << "--start seg2.x" << endl;
    ll low = -1e9, high = hit.y, mid;
    for(int iter = 0; iter < 50; iter++)
    {
        if(high-low <= 0) break;
        mid = (low+high)/2;
        if(test(hit.x, mid) == true)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        if(center == 1) return;
    }
    seg2.x = low;
//    cerr << "--start seg2.y" << endl;
    low = hit.y, high = 1e9;
    for(int iter = 0; iter < 50; iter++)
    {
        if(high-low <= 0) break;
        mid = (low+high)/2;
        if(test(hit.x, mid) == false)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        if(center == 1) return;
    }
    seg2.y = low;
}

void ans(ll x, ll y)
{
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
        {
            bool res = test(x+i, y+j);
            if(center == 1) return;
        }
}

void process()
{
    getHit();
    if(center == 1) return;
    getSeg1();
//    cerr << "seg1 = " << seg1.x << "," << seg1.y << endl;
    if(center == 1) return;
    getSeg2();
//    cerr << "seg2 = " << seg2.x << "," << seg2.y << endl;
    if(center == 1) return;
    ans((seg1.x+seg1.y)/2, (seg2.x+seg2.y)/2);
    if(center == 1) return;
}

