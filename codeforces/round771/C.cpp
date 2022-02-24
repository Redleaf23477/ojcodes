#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        int ans = 0;
        for (int i = 0, r = 1; i < n; i++) {
            if (arr[i] > r) {
                r = arr[i];
            } else if (r == i+1) {
                ans += 1;
                r += 1;
            }
        }
        cout << ans << "\n";
    }
}

