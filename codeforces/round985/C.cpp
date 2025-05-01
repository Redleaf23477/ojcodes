#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    if (n == 1) {
        cout << 0 << "\n"; return;
    }

    auto good = [&](int ans) {
        vector<int> left(3 * n,  -1), right(3 * n, -1);
        // prefix
        for (int i = 0, r = 0; i < n; i++) {
            if (arr[i] > r) r++;
            else if (arr[i] < r) r--;
            if (left[r] == -1) left[r] = i;
        }
        // suffix
        for (int i = n - 1, r = ans; i >= 0; i--) {
            if (arr[i] > r - 1) r--;
            else if (arr[i] < r + 1) r++;
            if (r >= 0 && right[r] == -1) right[r] = i;
        }

        /*
        cerr << "=== bs = " << ans << " ===" << endl;
        for (int i = 0; i < n; i++) cerr << left[i] << " ";
        cerr << endl;
        for (int i = 0; i < n; i++) cerr << right[i] << " ";
        cerr << endl;
        */

        // match prefix and suffix
        if (left[ans] != -1 || right[0] != -1) return true;
        for (int r = 1; r < n; r++) {
            if (left[r] == -1 || right[r] == -1) continue;
            if (left[r] + 1 < right[r]) return true;
        }
        return false;
    };

    int low = 1, high = n, mid, ans = 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (good(mid)) ans = mid, low = mid + 1;
        else high = mid;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

