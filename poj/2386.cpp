// lake counting
// dfs
#include <cstdio>

using namespace std;
typedef long long int ll;

const int N = 110;

int R, C;
char maze[N][N];

void init();
void process();

int main()
{
    init();
    process();
    return 0;
}

void init()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
            scanf("%s", maze[i]);
}

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int r, int c)
{
    if(r < 0 || r >= R) return;
    if(c < 0 || c >= C) return;
    if(maze[r][c] != 'W') return;
    maze[r][c] = '.';
    for(int d = 0; d < 8; d++)
        dfs(r+dr[d], c+dc[d]);
}

void process()
{
    int cnt = 0;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            if(maze[r][c] == 'W') dfs(r, c), cnt++;
    printf("%d\n", cnt);
}

