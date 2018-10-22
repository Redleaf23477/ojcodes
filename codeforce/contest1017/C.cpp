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
    int n; cin >> n;
    int sqrtn = sqrt(n);
    int bkn = n/sqrtn;
    if(bkn*sqrtn < n) bkn++;

    //cout << sqrtn << " " << bkn << endl;

    for(int i = bkn-1; i >= 0; i--)
    {
        for(int k = sqrtn*i+1, j = 0; k <= n && j < sqrtn; k++, j++)
        {
            cout << k << " ";
        }
    }
    cout << endl;
}

