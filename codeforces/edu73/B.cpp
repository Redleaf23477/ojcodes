//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 101;

int n;
char board[N][N];
bool vis[N][N];

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
    cin >> n;
}

int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void bfs(int r, int c, char col='W')
{
    queue<tuple<int,int,char>> q;
    q.emplace(r,c,col);
    vis[r][c] = true;
    while(!q.empty())
    {
        tie(r,c,col) = q.front(); q.pop();
        board[r][c] = col;
        for(int d = 0; d < 8; d++)
        {
            int nr = r+dr[d], nc = c+dc[d];
            if(0 <= nr && nr < n && 0 <= nc && nc < n)
            {
                if(vis[nr][nc]) continue;
                vis[nr][nc] = true;
                q.emplace(nr, nc, 'W'+'B'-col);
            }
        }
    }
}

void process()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(vis[i][j]) continue;
            bfs(i,j);
        }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << board[i][j];
        cout << endl;
    }
}

