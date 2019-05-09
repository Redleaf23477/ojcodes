//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;

int w;
int d[10];

void init();
void process();

int32_t main()
{
    int T; cin >> T >> w;
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    for(int i = 1; i <= 6; i++)
    {
        cout << i << endl;
        cin >> d[i];
    }
}

void process()
{
    int t1 = d[2]-d[1];
    int t2 = d[3]-d[2];
    int t3 = d[4]-d[3];
    int t4 = d[5]-d[4];
    int t5 = d[6]-d[5];
    int t6 = d[6]-2*d[3];
    int r1 = (t6-4*t1)/40;
    int r2 = t1-2*r1;
    int r3 = t2-4*r1;
    int r4 = t3-8*r1-2*r2;
    int r5 = t4-16*r1;
    int r6 = t5-32*r1-4*r2-2*r3;
    cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << " " << r6 << endl;
    int x; cin >> x;

}

