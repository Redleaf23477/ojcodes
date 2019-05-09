//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int R, C;
bool arr[30][30];

void init();
void process();

int32_t main()
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
}

void err(int idx)
{
    cout << "line " << idx << " error" << endl;
}

void process()
{
    int pr = -1, pc = -1;
    int r, c, idx = 0; 
    while(cin >> r >> c)
    {
        if(++idx == R*C) break;
        // check
        if(pr != -1 && pc != -1)
        {
            if(arr[r][c]) err(idx);
            if(r == pr || c == pc) err(idx);
            if(r + c == pr + pc) err(idx);
            if(r - c == pr - pc) err(idx);
        }
        arr[r][c] = 1;
        pr = r, pc = c;
    }
    for(int r = 1; r <= R; r++)
    {
        for(int c = 1; c <= C; c++)
            cout << arr[r][c];
        cout << endl;
    }
}

