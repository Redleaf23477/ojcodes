//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 3003;

int n;
ll arr[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++) arr[i] += arr[i-1];
}

void process()
{
    int ans = 1;
    ll prv = arr[0], prvIdx = 0;
    while(true)
    {
        int idx = lower_bound(arr, arr+n, arr[prvIdx]+prv)-arr;
        if(idx == n) break;
        ans++;
        prv = arr[idx]-arr[prvIdx];
        prvIdx = idx;
    }
    cout << ans << endl;
}

