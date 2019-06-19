//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int N = 55;

int len;
int r1, c1, r2, c2;
vector<P> side1, side2;
char arr[N][N];
bool vis[N][N];

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
    cin >> len;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            cin >> arr[i][j];
}

bool legal(int r, int c)
{
    return 0 <= r && r < len && 0 <= c && c < len;
}

int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, -1, 1};
void bfs(int r, int c, vector<P> &side)
{
    memset(vis, 0, sizeof(vis));
    queue<P> q; q.emplace(r, c); vis[r][c] = true;
    while(!q.empty())
    {
        P f = q.front(); q.pop();
        side.push_back(f);
        for(int d = 0; d < 4; d++)
        {
            int nr = f.first+dr[d], nc = f.second+dc[d];
            if(legal(nr, nc) && !vis[nr][nc] && arr[nr][nc] == '0')
            {
                vis[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }
    }
}

ll dist(P &x, P &y)
{
    ll xx = (x.first-y.first), yy = (x.second-y.second);
    return xx*xx + yy*yy;
}

void process()
{
    bfs(r1, c1, side1);
    bfs(r2, c2, side2);

    ll mn = (1ll<<60);
    for(auto x:side1)
    {
        for(auto y:side2)
        {
            mn = min(mn, dist(x, y));
        }
    }
    cout << mn << endl;
}

