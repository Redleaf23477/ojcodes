//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1010;

int R, C;
char sky[N][N];
int rSum[N][N], lSum[N][N], uSum[N][N], dSum[N][N];
int star[N][N];
int vSum[N][N], hSum[N][N];

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
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> sky[i][j];
    // build
    for(int i = 0; i < R; i++)
    {
        rSum[i][0] = (sky[i][0] == '*');
        for(int j = 1; j < C; j++) rSum[i][j] = (sky[i][j] == '*'? rSum[i][j-1]+1 : 0);
        lSum[i][C-1] = (sky[i][C-1] == '*');
        for(int j = C-2; j >= 0; j--) lSum[i][j] = (sky[i][j] == '*'? lSum[i][j+1]+1 : 0);
    }
    for(int j = 0; j < C; j++)
    {
        uSum[0][j] = (sky[0][j] == '*');
        for(int i = 1; i < R; i++) uSum[i][j] = (sky[i][j] == '*'? uSum[i-1][j]+1 : 0);
        dSum[R-1][j] = (sky[R-1][j] == '*');
        for(int i = R-2; i >= 0; i--) dSum[i][j] = (sky[i][j] == '*'? dSum[i+1][j]+1 : 0);
    }
    // cal max len
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            star[r][c] = min({ rSum[r][c], lSum[r][c], uSum[r][c], dSum[r][c] });
        }
}

void process()
{
    bool success = true;
    int starNum = 0;
//    // debug
//    for(int i = 0; i < R; i++)
//    {
//        for(int j = 0; j < C; j++)
//            cout << star[i][j] << " ";
//        cout << endl;
//    }
    // fill sky with star
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            if(star[r][c] > 1)
            {
                starNum++;
                int dlen = star[r][c]-1;
                vSum[r][c-dlen]++, vSum[r][c+dlen+1]--;
                hSum[r-dlen][c]++, hSum[r+dlen+1][c]--;
            }
        }
    // check if star can fill the sky
    // vertical
    for(int r = 0; r < R; r++)
    {
        int ptr = 0;
        for(int c = 0; c < C; c++)
        {
            ptr += vSum[r][c];
            if(ptr > 0 && sky[r][c] == '*') sky[r][c] = 'x';
        }
    }
    // horizontal
    for(int c = 0; c < C; c++)
    {
        int ptr = 0;
        for(int r = 0; r < R; r++)
        {
            ptr += hSum[r][c];
            if(sky[r][c] == '*')
            {
                if(ptr > 0) sky[r][c] = 'x';
                else success = false;
            }
        }
    }
    // print answer
    if(success)
    {
        cout << starNum << endl;
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
            {
                if(star[r][c] > 1) cout << r+1 << " " << c+1 << " " << star[r][c]-1 << endl;
            }
    }
    else cout << -1 << endl;
}

