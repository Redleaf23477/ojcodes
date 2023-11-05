#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool sorted(vector<int> &arr, int l, int r) {
    for (int i = l; i + 1 < r; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int l = 1;
    for (int len = 1; l + len <= n; l += len, len *= 2) {
        if (!sorted(arr, l, l + len)) {
            cout << "NO\n"; return;
        }
    }
    if (!sorted(arr, l, n)) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

