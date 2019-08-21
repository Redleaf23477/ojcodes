//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 1010;
const ll INF = 1ll << 60;

int R, C;
int sr, sc, er, ec;
ll arr[N][N];
bool vis[N][N];
ll dist[N][N];

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
    cin >> R >> C;
    cin >> sr >> sc >> er >> ec;
    sr--, sc--, er--, ec--;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            cin >> arr[r][c];
            dist[r][c] = INF;
        }
}

void process()
{
    using Node = tuple<ll, int, int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(0, sr, sc); dist[sr][sc] = 0;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
    while(!pq.empty())
    {
        ll len, r, c;
        tie(len, r, c) = pq.top(); pq.pop();
        if(r == er && c == ec) break;
        vis[r][c] = true;
        for(int d = 0; d < 4; d++)
        {
            ll nr = r+dr[d], nc = c+dc[d];
            if(0 <= nr && nr < R && 0 <= nc && nc < C)
            {
                ll nxtDist = abs(arr[r][c]-arr[nr][nc])+len;
                if(nxtDist < dist[nr][nc])
                {
                    dist[nr][nc] = nxtDist;
                    pq.emplace(nxtDist, nr, nc);
                }
            }
        }
    }
    cout << dist[er][ec] << endl;
}

