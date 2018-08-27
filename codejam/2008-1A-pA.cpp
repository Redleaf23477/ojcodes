//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1000;

int n;
ll va[N], vb[N];

void init();
void process();

int main()
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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> va[i];
    for(int i = 0; i < n; i++) cin >> vb[i];
    sort(va, va+n);
    sort(vb, vb+n);
}

void process()
{
    ll tot = 0;
    for(int i = 0; i < n; i++)
        tot += va[i]*vb[n-i-1];
    cout << tot << endl;
}

