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
ll prog[N];
Pos wind[N];
Pos suf[N];

Pos operator + (const Pos lhs, const Pos rhs) { return Pos(lhs.x+rhs.x, lhs.y+rhs.y); }
Pos operator - (const Pos lhs, const Pos rhs) { return Pos(lhs.x-rhs.x, lhs.y-rhs.y); }
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
}

void process()
{
    ll ori = abs(to-from);
    ll largestProgress = 0;

    // within a week
    suf[0] = wind[0];
    ll newDist = abs(to-from-suf[0])-1;
    prog[0] = ori-newDist;
    if(newDist > largestProgress) largestProgress = newDist;
    if(abs(to-from-suf[0]) <= 1)
    {
        cout << 1 << endl;
        return;
    }
    for(int i = 1; i < len; i++)
    {
        suf[i] = suf[i-1]+wind[i];
        newDist = abs(to-from-suf[i])-(i+1);
        prog[i] = ori-newDist;
        if(newDist > largestProgress) largestProgress = newDist;
        
        if(abs(to-from-suf[i]) <= i+1)
        {
            cout << i+1 << endl;
            return;
        }
    }
    
    // if after a week but not nearer, gg
    if(prog[len-1] <= 0)
    {
        cout << -1 << endl;
        return;
    }
    
    // do some calculate
    
    ll cyc = ori/prog[len-1];
    ll rest = ori - cyc * prog[len-1];

//    cout << "cyc = " << cyc << endl;
//    for(int i = 0; i < len; i++) cout << prog[i] << " ";
//    cout << endl;

    for(int i = 0; i < len; i++)
    {
        if(rest <= prog[i]) 
        {
            cout << len*cyc+i+1 << endl;
            return;
        }
    }
}

