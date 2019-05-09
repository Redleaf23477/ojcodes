//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int sz, n;
string her;

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
    cin >> sz >> her;
    n = 2*sz-2;
}

void process()
{
    string my = her;
    int herPos = 0, myPos = 0;
    for(int i = 0; i < n; i++)
    {
        my[i] = 'E'+'S'-my[i];
    }
    cout << my << endl;
}

