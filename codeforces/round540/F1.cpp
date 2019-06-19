//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 300005;
const int RED = 1, BLUE = 2, BLACK = 0;

int vn;
int color[N];
int tot[3];
ll ans;

vector<int> G[N];

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
    cin >> vn;
    for(int i = 1; i <= vn; i++) 
    {
        cin >> color[i];
        tot[color[i]]++;
    }
    for(int i = 1; i < vn; i++)
    {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

pair<ll, ll> dfs(int x, int p)
{
    pair<ll, ll> col;
    for(auto c:G[x])
    {
        if(c == p) continue;
        pair<ll, ll> sub = dfs(c, x);
        if((sub.first == 0 || sub.second == 0) && (tot[RED]-sub.first == 0 || tot[BLUE]-sub.second == 0)) ans++;
        col.first += sub.first, col.second += sub.second;
    }
    if(color[x] == RED) col.first++;
    if(color[x] == BLUE) col.second++;
    return col;
}

void process()
{
    dfs(1, 1);
    cout << ans << endl;
}

