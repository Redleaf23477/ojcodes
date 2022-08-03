#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL n, k; cin >> n >> k;
    vector<LL> arr(n); 
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (auto x : arr) {
        while (k * 2 < x) {
            k = k * 2, ans += 1;
        }
        k = max(k, x);
    }
    cout << ans << "\n";
}

