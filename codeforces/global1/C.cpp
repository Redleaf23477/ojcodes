//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int q;
const int N = 30;
int n;
int arr[N];

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
    cin >> q;
    n = 25;
    for(int i = 1; i <= 25; i++)
    {
        arr[i-1] = (1<<i)-1;
    }
}

int bigFac(int x)
{
    for(int i = 2; i*i <= x; i++)
    {
        if(x%i == 0) return x/i;
    }
    return 1;
}

void process()
{
    while(q--)
    {
        int x; cin >> x;
        int res = *lower_bound(arr, arr+n, x);
        if(res == x) cout << bigFac(x) << endl;
        else cout << res << endl;
    }
}

