//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    int pa, ma, son, mar; cin >> pa >> ma >> son >> mar;
    for(int b = pa; b <= 2*pa; b++)
    {
        for(int m = ma; m <= 2*ma && m < b; m++)
        {
            for(int s = son; s <= 2*son && s < m; s++)
            {
                if((mar <= s) && (2*mar < b) && (2*mar < m) && (2*mar >= s))
                {
                    cout << b << endl << m << endl << s << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

