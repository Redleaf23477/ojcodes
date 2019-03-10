//
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<double, int> Event;
#define x first
#define idx second

const int N = 40004;

struct Circle
{
    double x, y, rad;
};

bool operator < (const Event &lhs, const Event &rhs)
{
    return lhs.x < rhs.x || (lhs.x==rhs.x && lhs.idx < rhs.idx);
}

bool operator < (const Circle &lhs, const Circle &rhs)
{
    return lhs.y < rhs.y || (lhs.y==rhs.y && lhs.x < rhs.x);
}

int n;
Circle arr[N];
priority_queue<Event, vector<Event>, greater<Event> > event;

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf%lf%lf", &arr[i].rad, &arr[i].x, &arr[i].y);
        event.push(make_pair(arr[i].x-arr[i].rad, i));
    }
}

bool notInCircle(const Circle &a, const Circle &b)
{
    double centerDist2 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    double radSum = a.rad+b.rad;
    return radSum*radSum < centerDist2;
}

void process()
{
    vector<int> ans;
    vector<bool> inSet(n, false);
    set<Circle> cirSet;
    while(!event.empty())
    {
        int idx = event.top().idx; event.pop();
        if(inSet[idx] == false)
        {
            bool okay = true;
            set<Circle>::iterator it = cirSet.upper_bound(arr[idx]);
            if(it != cirSet.end()) okay &= notInCircle(arr[idx], *it);
            if(it != cirSet.begin()) { it--; okay &= notInCircle(arr[idx], *it); }
            if(okay) 
            {
                cirSet.insert(arr[idx]);
                inSet[idx] = true;
                event.push(make_pair(arr[idx].x+arr[idx].rad, idx));
            }
        }
        else
        {
            ans.push_back(idx+1);
            set<Circle>::iterator it = cirSet.find(arr[idx]);
            cirSet.erase(it);
            inSet[idx] = false;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%zu\n%d", ans.size(), ans[0]);
    for(size_t i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
    printf("\n");
}

