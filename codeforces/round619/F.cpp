// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

const int N = 1000, K = 40;
const int INF = 1<<30;

int R, C, k;
int arr[N][N];
int dist[K][N][N];
vector<tuple<int,int>> pos[K];

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

bool legal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

const int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
void bfs(int color, int dist[N][N])
{
    vector<bool> jump(k, false);
    queue<tuple<int,int>> q;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            if(arr[r][c] == color) 
            {
                dist[r][c] = 0;
                q.emplace(r, c);
            }
    int r, c, nr, nc;
    while(!q.empty())
    {
        tie(r, c) = q.front(); q.pop();
        if(jump[arr[r][c]] == false)
        {
            jump[arr[r][c]] = true;
            for(auto t : pos[arr[r][c]])
            {
                tie(nr, nc) = t;
                if(dist[nr][nc] != INF) continue;
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        for(int d = 0; d < 4; d++)
        {
            nr = r+dr[d], nc = c+dc[d];
            if(!legal(nr, nc) || dist[nr][nc] != INF) continue;
            dist[nr][nc] = dist[r][c]+1;
            q.emplace(nr, nc);
        }
    }
    /*
    cerr << var(color) << " : " << endl;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cout << dist[r][c] << " \n"[c==C-1];
    */
}

void init()
{
    cin >> R >> C >> k;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            cin >> arr[r][c];
            arr[r][c]--;
            pos[arr[r][c]].emplace_back(r, c);
        }
    for(int color = 0; color < k; color++)
    {
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                dist[color][r][c] = INF;
        bfs(color, dist[color]);
    }
}

void process()
{
    int q; cin >> q;
    int r1, c1, r2, c2;
    while(q--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        int ans = abs(r1-r2) + abs(c1-c2);
        for(int color = 0; color < k; color++)
        {
            ans = min(ans, dist[color][r1][c1]+dist[color][r2][c2]+1);
        }
        cout << ans << endl;
    }
}

