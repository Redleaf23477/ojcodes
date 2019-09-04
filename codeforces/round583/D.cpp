//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int R, C;
vector<string> maze;
vector<vector<bool>> good; // connected to end

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
    maze.resize(R);
    good.resize(R);
    for(int r = 0; r < R; r++) 
    {
        cin >> maze[r];
        good[r].resize(C, false);
    }

}

bool valid_dfs(int r, int c) 
{ 
    return (0 <= r && r < R && 0 <= c && c < C && maze[r][c] != '#');
}

const int dr[] = {1, 0}, dc[] = {0, 1};

void dfs(int r, int c, vector<vector<bool>> &vis)
{
    vis[r][c] = true;
    for(int d = 0; d < 2; d++)
    {
        int nr = r + dr[d], nc = c + dc[d];
        if(!valid_dfs(nr, nc)) continue;
        if(!vis[nr][nc]) dfs(nr, nc, vis);
        if(good[nr][nc] == true) good[r][c] = true;
    }
}

bool valid_bfs(int r, int c) 
{ 
    return (0 <= r && r < R && 0 <= c && c < C && good[r][c]);
}

bool bfs(int sr, int sc)
{
    vector<vector<bool>> vis(R); for(auto &v : vis) v.resize(C, false);
    queue<pair<int,int>> q;
    q.emplace(sr, sc); vis[sr][sc] = true;
    while(!q.empty())
    {
        auto f = q.front(); q.pop();
        int r = f.first, c = f.second;
//        cout << "xx" << r << " " << c << " " << q.size() << endl;
        if(r == R-1 && c == C-1) break;
        if((r != sr || c != sc) && q.empty()) return true;
        for(int d = 0; d < 2; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(!valid_bfs(nr, nc)) continue;
            if(vis[nr][nc]) continue;
            vis[nr][nc] = true;
            q.emplace(nr, nc);
        }
    }
    return false;
}

void process()
{
    vector<vector<bool>> vis(R); for(auto &v : vis) v.resize(C, false);
    good[R-1][C-1] = true;
    dfs(0, 0, vis);
//    for(auto r : vis) { for(auto c : r) cout << c << " "; cout << endl; }
    if(good[0][0] == false) cout << 0 << endl;
    else if(bfs(0, 0)) cout << 1 << endl;
    else cout << 2 << endl;
}

