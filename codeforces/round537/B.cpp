//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;

int n, inc, op;
ll arr[N];
ll sum[N];

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
    cin >> n >> inc >> op;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr, arr+n+1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+arr[i];
}

void process()
{
    double mx = 0;
    for(int leave = 0; leave <= n-1 && leave <= op; leave++)
    {
        int quotaToInc = op - leave;
        ll tmpSum = sum[n]-sum[leave];
        ll totInc = min(quotaToInc, inc*(n-leave));
        double avg = tmpSum + totInc;
        avg /= n-leave;
        mx = max(mx, avg);
    }
    cout << fixed << setprecision(8) << mx << endl;
}
