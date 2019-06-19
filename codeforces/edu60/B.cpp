//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

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
    int n, m, k; cin >> n >> m >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll largest = arr.back(), sec = arr[arr.size()-2];
    ll p = m / (k+1), r = m % (k+1);
    ll sum = largest * p * k + sec * p + largest * r;
    cout << sum << endl;

}

void process()
{
}

