//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll h, n;
vector<ll> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> h >> n;
    arr.resize(n+1);
    for(int i = 0; i < n; i++) cin >> arr[i];
    arr[n] = 0;
}

void process()
{
    ll ans = 0, now = h, to = 1;
    while(to < n)
    {
        now = arr[to]+1;
        if(arr[to] == 0) break;
        if(arr[to+1] == now-2) to = to+2;
        else ans++, to = to+1;
    }
    cout << ans << endl;
}

