// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

const int N = 1010;

int R, C;
char arr[N][N];

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
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> arr[r][c];
}

bool ok()
{
    bool hasEmptyRow = false, hasEmptyCol = false;
    // row
    for(int r = 0; r < R; r++)
    {
        bool empty = true;
        int up = 0;
        char prv = '.';
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] == '#')
            {
                empty = false;
                if(prv == '.') up++;
            }
            prv = arr[r][c];
        }
        if(up > 1) return false;
        if(empty) hasEmptyRow = true;
    }
    // col
    for(int c = 0; c < C; c++)
    {
        bool empty = true;
        int up = 0;
        char prv = '.';
        for(int r = 0; r < R; r++)
        {
            if(arr[r][c] == '#')
            {
                empty = false;
                if(prv == '.') up++;
            }
            prv = arr[r][c];
        }
        if(up > 1) return false;
        if(empty) hasEmptyCol = true;
    }
    if(hasEmptyRow != hasEmptyCol) return false;
    return true;
}

bool legal(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

int bfs()
{
    int cnt = 0;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] != '#') continue;
            cnt++;
            queue<tuple<int,int>> q;
            q.emplace(r, c); arr[r][c] = 'x';
            while(!q.empty())
            {
                int _r, _c;
                tie(_r, _c) = q.front(); q.pop();
                for(int d = 0; d < 4; d++)
                {
                    int nr = _r+dr[d], nc = _c + dc[d];
                    if(legal(nr, nc) && arr[nr][nc] == '#')
                    {
                        q.emplace(nr, nc);
                        arr[nr][nc] = 'x';
                    }
                }
            }
        }
    return cnt;
}

void process()
{
    if(!ok()) cout << -1 << endl;
    else cout << bfs() << endl;
}

