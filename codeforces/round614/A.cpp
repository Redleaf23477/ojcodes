//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, s, k;
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
    cin >> n >> s >> k;
    arr.resize(k);
    for(int i = 0; i < k; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
}

void process()
{
    ll ans = 1<<30;
    for(int i = 0; i < 1010; i++)
    {
        ll up = s + i, down = s - i;
        if(up <= n && binary_search(arr.begin(), arr.end(), up) == false) ans = min(ans, abs(s-up));
        if(down > 0 && binary_search(arr.begin(), arr.end(), down) == false) ans = min(ans, abs(s-down));
    }
    cout << ans << endl;
}

