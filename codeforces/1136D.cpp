//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int N = 300005;
const int M = 500005;

int n, m;
int remap[N];
vector<int> G[N];
int byeNum;
bool bye[N];

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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        remap[x] = i;
    }
    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        x = remap[x], y = remap[y];
        if(y > x) G[x].push_back(y);
    }
    for(int i = 0; i < n; i++) sort(G[i].begin(), G[i].end());
    /*
    for(int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for(auto x:G[i]) cout << x << " ";
        cout << endl;
    }
    */
}

void process()
{
    int ans = 0;
    for(int i = n-2; i >= 0; i--)
    {
        int cnt = G[i].size();
        for(auto x:G[i])
        {
            if(bye[x]) cnt--;
        }
        if(i + cnt + byeNum == n-1) 
        {
            ans++, bye[i] = true, byeNum++;
        }
    }
    cout << ans << endl;
}

