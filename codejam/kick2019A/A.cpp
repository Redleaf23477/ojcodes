//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;
int n, p;
ll arr[N], fix[N];

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
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr, arr+n+1);
    for(int i = 1; i <= n; i++)
        fix[i] = fix[i-1]+arr[i];
}

void process()
{
    ll mn = (1ll<<60);
    for(int i = p; i <= n; i++)
    {
        ll need = arr[i]*p-(fix[i]-fix[i-p]);
        mn = min(mn, need);
    }
    cout << mn << endl;
}

