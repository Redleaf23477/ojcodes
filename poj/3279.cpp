//
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long int ll;

const int N = 20;

int R, C;
int arr[N][N], cpy[N][N];
int tmp[N][N], mnPlate[N][N];

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
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            scanf("%d", &arr[r][c]);
}

void flip(int r, int c)
{
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    tmp[r][c]++, cpy[r][c] ^= 1;
    for(int i = 0; i < 4; i++)
    {
        int nr = r+dr[i], nc = c+dc[i];
        if(0 <= nr && nr < R && 0 <= nc && nc < C)
            cpy[nr][nc] ^= 1;
    }
}

void process()
{
    int mn = (1<<30);
    for(int r0 = 0; r0 < (1<<C); r0++)
    {
        bool ok = true;
        int cnt = 0;
        memcpy(cpy, arr, sizeof(arr));
        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < C; i++)
        {
            if(((r0>>i)&1) == 1) flip(0, i), cnt++;
        }
        for(int r = 1; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(cpy[r-1][c] == 1) flip(r, c), cnt++;
            }
        }
        for(int c = 0; c < C; c++)
            if(cpy[R-1][c] == 1) ok = false;
        if(ok && cnt < mn) 
        {
            mn = cnt;
            memcpy(mnPlate, tmp, sizeof(tmp));
        }
    }
    if(mn == (1<<30)) printf("IMPOSSIBLE\n");
    else
    {
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                printf("%d%c", mnPlate[r][c], " \n"[c==C-1]);
    }
}

