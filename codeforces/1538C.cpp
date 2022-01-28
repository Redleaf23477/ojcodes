#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> arr(n); 
        for (auto &x : arr) cin >> x;
        sort(arr.begin(), arr.end());

        LL ans = 0;
        for (int i = 1; i < n; i++) {
            int L = l - arr[i];
            int R = r - arr[i];
            ans += upper_bound(arr.begin(), arr.begin() + i, R) - lower_bound(arr.begin(), arr.begin() + i, L);
        }
        cout << ans << endl;
    }
}

