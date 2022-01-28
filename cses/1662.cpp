#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
        x = (x % n + n) % n;
    }
    map<int,int> mp;
    mp[0] = 1;
    LL ans = 0;
    for (int i = 0, sum = 0; i < n; i++) {
        sum = (sum + arr[i]) % n;
        ans += mp[sum];
        mp[sum] += 1;
    }
    cout << ans << "\n";
}

