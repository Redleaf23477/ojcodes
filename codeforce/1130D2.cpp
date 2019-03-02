//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 5050;
const int INF = 1<<30;

int vn, cn;
int candyNum[N];
int nearestCandyDist[N];

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
    cin >> vn >> cn;
    for(int i = 0; i < vn; i++) nearestCandyDist[i] = INF;
    for(int i = 0; i < cn; i++)
    {
        int from, to; cin >> from >> to; from--, to--;
        candyNum[from]++;
        nearestCandyDist[from] = min(nearestCandyDist[from], (to-from+vn)%vn);
    }
}

void process()
{
    for(int i = 0; i < vn; i++)
    {
        int furthest = 0;
        for(int j = 0; j < vn; j++)
        {
            int pos = (i+j)%vn;
            if(candyNum[pos] == 0) continue;
            int dist = j + vn*(candyNum[pos]-1) + nearestCandyDist[pos];
            furthest = max(furthest, dist);
        }
        cout << furthest << " ";
    }
    cout << endl;
}

