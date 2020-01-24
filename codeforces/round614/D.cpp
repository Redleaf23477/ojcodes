//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> Pt;
#define x first
#define y second

ll X0, Y0, Ax, Bx, Ay, By;
ll Xs, Ys, t;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> X0 >> Y0 >> Ax >> Ay >> Bx >> By;
    cin >> Xs >> Ys >> t;
}

ll ptDist(const Pt &lhs, const Pt &rhs)
{
    return abs(lhs.x - rhs.x) + abs(lhs.y - rhs.y);
}

void process()
{
    ll mx = 0;
    vector<Pt> pt;
    for(int i = 0; true; i++)
    {
        if(i == 0) pt.emplace_back(X0, Y0);
        else if(pt.size() <= i) pt.emplace_back(Ax * pt.back().x + Bx, Ay * pt.back().y + By);

        ll dist = abs(Xs - pt.back().x) + abs(Ys - pt.back().y);
        if(dist > t)
        {
            if(pt.back().y <= Ys) continue;
            else break;
        }
        ll collect = 1;
        ll goToBot = 0;
        // go down
        for(int j = i-1; j >= 0 && dist <= t; j--)
        {
            ll d = ptDist(pt[j], pt[j+1]);
            dist += d, goToBot += d;
            if(dist <= t) collect++;
        }
        dist += goToBot;
        // go up
        for(int j = i+1; dist <= t; j++)
        {
            if(pt.size() <= j) pt.emplace_back(Ax * pt.back().x + Bx, Ay * pt.back().y + By);
            ll d = ptDist(pt[j], pt[j-1]);
            dist += d;
            if(dist <= t) collect++;
        }
        mx = max(mx, collect);
    }
    cout << mx << endl;
}

