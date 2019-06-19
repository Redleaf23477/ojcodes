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
    ll n, k; cin >> n >> k;
    vector<ll> arr(n), ans(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll rst = k;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= rst)
        {
            int cnt = 1;
            arr[i] -= rst;
            cnt += arr[i]/k;
            rst = k-(arr[i]%k);
            ans[i] = cnt;
        }
        else
        {
            rst -= arr[i];
            ans[i] = 0;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
}

