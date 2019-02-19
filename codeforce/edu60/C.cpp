//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pos;
#define x first
#define y second

const int N = 100005;

Pos from, to;
int len;
Pos wind[N];
Pos suf[N];

Pos operator + (const Pos lhs, const Pos rhs) { return Pos(lhs.x+rhs.x, lhs.y+rhs.y); }
Pos operator - (const Pos lhs, const Pos rhs) { return Pos(lhs.x-rhs.x, lhs.y-rhs.y); }
Pos operator * (const ll lhs, const Pos rhs) { return Pos(lhs*rhs.x, lhs*rhs.y); }
int abs(Pos p) { return abs(p.x)+abs(p.y); }


void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> from.x >> from.y >> to.x >> to.y;
    cin >> len;
    for(int i = 0; i < len; i++)
    {
        char ch; cin >> ch;
        if(ch == 'U') wind[i].y = 1;
        else if(ch == 'D') wind[i].y = -1;
        else if(ch == 'L') wind[i].x = -1;
        else wind[i].x = 1;
    }
    for(int i = 0; i < len; i++) suf[i+1] = suf[i]+wind[i];
}

bool ok(ll day)
{
    ll q = day/len, r = day%len;
    Pos pos = from + q*suf[len] + suf[r];
    ll delta = abs(to-pos);
    cerr << ".." << day << " => " << (day >= delta) << endl;
    return day >= delta;
}

void process()
{
    ll low = 1, high = 200000000000000ll, mid, ans = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}
