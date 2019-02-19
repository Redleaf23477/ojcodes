//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

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
}

void process()
{
    int g, gp, z, green, purple, black;
    cin >> g >> gp >> z >> green >> purple >> black;
    if(g > green)
    {
        cout << "NO" << endl; return;
    }
    green -= g;
    if(gp > green+purple)
    {
        cout << "NO" << endl; return;
    }
    int all = green+purple+black-gp;
    if(z > all)
    {
        cout << "NO" << endl; return;
    }
    cout << "YES" << endl;
}

