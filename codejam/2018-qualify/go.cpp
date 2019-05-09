//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;


const int N = 1000;
int a, len;
int orchard[5][N];

void init();
void process();

int32_t main()
{
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    cin >> a;
    len = a/3 + (a%3!=0);
    memset(orchard, 0, sizeof(orchard));
}

void perform(int x, int y)
{
    assert(2 <= x && x <= 999);
    assert(2 <= y && y <= 999);
    cout << x << " " << y << endl;
}

bool getResult()
{
    int x, y; cin >> x >> y;
    if(x == 0 && y == 0) return true;
    if(x == -1 && y == -1) assert(false);
    orchard[x][y] = 1;
    return false;
}

void process()
{
    // make a 3*len rectangle
    // center x = 2 ~ len-1
    int x = 2;
    do
    {
        if(len > 3) perform(2, min(x, len-1));
        else perform(2, 2);
        if(getResult() == true) return;
        if(orchard[1][x-1] && orchard[2][x-1] && orchard[3][x-1]) x++;
    } while(true);
}

