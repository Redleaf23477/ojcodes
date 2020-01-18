//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int y;

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
    cin >> y;
}

bool isleap(int y)
{
    if(y % 4 != 0) return false;
    if(y % 100 != 0) return true;
    if(y % 400 == 0) return true;
    return false;
}

void process()
{
    int acc = 0;
    for(int yy = y; true; yy++)
    {
        if(isleap(yy)) acc += 366;
        else acc += 365;
        acc %= 7;
        if(acc == 0 && isleap(yy+1) == isleap(y)) { cout << yy+1 << endl; return; }
    }
}

