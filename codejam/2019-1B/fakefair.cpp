//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n, k;
vector<int> up, down;

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
    cin >> n >> k;
    up.resize(n);
    down.resize(n);
    for(int i = 0; i < n; i++)
        cin >> up[i];
    for(int i = 0; i < n; i++)
        cin >> down[i];
}

bool ok(int l, int r)
{
    ll mxup = -1, mxdown = -1;
    for(int i = l; i <= r; i++)
    {
        mxup = max(mxup, up[i]);
        mxdown = max(mxdown, down[i]);
    }
    if(abs(mxup-mxdown) <= k) return true;
    return false;
}

void process()
{
    ll ans = 0;
    for(int l = 0; l < n; l++)
        for(int r = l; r < n; r++)
        {
            if(ok(l, r)) ans++;
        }
    cout << ans << endl;
}

