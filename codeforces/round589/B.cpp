//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1003;
int R, C;
bool invalid;
int color[N][N];
const int NOTSURE = 0, BLACK = 1, WHITE = 2;

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
    invalid = false;
    for(int r = 0; r < R; r++)
    {
        int x; cin >> x;
        for(int c = 0; c < x; c++) 
        {
            if(color[r][c] == WHITE) invalid = true;
            color[r][c] = BLACK;
        }
        if(color[r][x] == BLACK) invalid = true;
        color[r][x] = WHITE;
    }
    for(int c = 0; c < C; c++)
    {
        int x; cin >> x;
        for(int r = 0; r < x; r++)
        {
            if(color[r][c] == WHITE) invalid = true;
            color[r][c] = BLACK;
        }
        if(color[x][c] == BLACK) invalid = true;
        color[x][c] = WHITE;
    }
}

void process()
{
    if(invalid) { cout << 0 << endl; return; }
    int cnt = 0;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            if(color[r][c] == NOTSURE) cnt++;
    ll ans = 1;
    while(cnt--)
    {
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans << endl;
}

