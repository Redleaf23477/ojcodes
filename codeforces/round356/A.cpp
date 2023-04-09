#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n = 5, sum = 0;
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
        sum += x;
    }
    int ans = sum;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) cnt++;
        }
        cnt = min(cnt, 3);
        if (cnt == 2 || cnt == 3) {
            ans = min(ans, sum - cnt * arr[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



