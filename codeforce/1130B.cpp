//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;
int n;
vector<int> sz[N];

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
    cin >> n;
    for(int i = 0; i < 2*n; i++)
    {
        int x; cin >> x;
        sz[x].push_back(i);
    }
}

void process()
{
    ll dist = 0;
    ll pos0 = 0, pos1 = 0;
    for(int i = 1; i <= n; i++)
    {
        ll stat1 = abs(sz[i][0]-pos0) + abs(sz[i][1]-pos1);
        ll stat2 = abs(sz[i][1]-pos0) + abs(sz[i][0]-pos1);
        if(stat1 < stat2)
        {
            dist += stat1;
            pos0 = sz[i][0], pos1 = sz[i][1];
        }
        else
        {
            dist += stat2;
            pos0 = sz[i][1], pos1 = sz[i][0];
        }
    }
    cout << dist << endl;
}

