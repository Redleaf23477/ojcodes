// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

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

int n;
vector<ll> arr;

void init()
{
    cin >> n; arr.assign(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> arr[i];
}

void process()
{
    vector<ll> dp(n+1, 1);
    for(int i = 1; i <= n; i++)
        for(int j = i+i; j <= n; j += i)
            if(arr[j] > arr[i]) dp[j] = max(dp[j], dp[i]+1);
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

