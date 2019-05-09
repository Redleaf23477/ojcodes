//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 20;

int R, C;
char mp[N][N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> R >> C;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> mp[r][c];
}

void process()
{
    // row
    int row = 0;
    for(int r = 0; r < R; r++)
    {
        bool good = true;
        for(int c = 0; c < C; c++)
        {
            if(mp[r][c] != '.') good = false;
        }
        if(good) row++;
    }

    int col = 0;
    for(int c = 0; c < C; c++)
    {
        bool good = false;
        for(int r = 0; r < R; r++)
        {
            if(mp[r][c] != '.') good = false;
        }
        if(good) col++;
    }

    if(
    cout << row+col << endl;
}

