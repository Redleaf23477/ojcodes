#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL solve(vector<LL> arr, int exceed) {
    LL ans = 0;
    for (int i = 0; i < 7; i++) {
        arr[i] -= arr[6];
        if (arr[i] < 0) return -1;
    }
    for (int i = 0; i < exceed; i++) {
        arr[i]--;
        if (arr[i] < 0) return -1;
    }

    for (int i = 0; i < 6; i++) {
        if (arr[i] < arr[i+1]) return -1;
    }

    for (int i = 5; i >= 0; i--) {
        if (ans < arr[i]) {
            LL d = arr[i] - ans;
            ans += d;
        }
    }

    return 1 + ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        vector<LL> arr(7);
        for (auto &x : arr) cin >> x;
        LL ans = -1;
        for (int exceed = 0; exceed <= 6; exceed++) {
            LL tmp = solve(arr, exceed);
            if (tmp != -1) {
                if (ans == -1 || tmp < ans) ans = tmp;
            }
        }
        cout << ans << "\n";
    }
}

