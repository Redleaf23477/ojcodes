//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<double, int> Node;
#define len first
#define idx second

struct Circle
{
    double x, y, r;
};

int vn;
vector<Circle> circle;


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
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int cn; cin >> cn;
    vn = cn+2; circle.resize(vn);
    for(int i = 0; i < cn; i++) cin >> circle[i].x >> circle[i].y >> circle[i].r;
    circle[cn] = (Circle){x1, y1, 0};
    circle[cn+1] = (Circle){x2, y2, 0};
}

double getDist(int i, int j)
{
    Circle &a = circle[i], &b = circle[j];
    double dx2 = (a.x-b.x)*(a.x-b.x);
    double dy2 = (a.y-b.y)*(a.y-b.y);
    double dist = sqrt(dx2 + dy2);
    double rsum = a.r + b.r;
    if(rsum >= dist) return 0;
    else return dist - rsum;
}

void process()
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    int start = vn-2, stop = vn-1;
    pq.emplace(0, start);
    vector<double> sp(vn, 1e18); sp[start] = 0;
    vector<bool> vis(vn, false); 
    while(!pq.empty())
    {
        Node f = pq.top(); pq.pop();
        if(vis[f.idx]) continue;
        sp[f.idx] = f.len;
        vis[f.idx] = true;
        if(f.idx == stop) break;
        for(int i = 0; i < vn; i++)
        {
            if(vis[i]) continue;
            double dist = getDist(f.idx, i);
            if(f.len+dist < sp[i])
            {
                sp[i] = f.len+dist;
                pq.emplace(sp[i], i);
            }
        }
    }
    cout << fixed << setprecision(10) << sp[stop] << endl;
}

