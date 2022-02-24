#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL good(LL d, const vector<LL> &arr) {
    LL l = 0, r = 1e9;
    for (auto x : arr) {
        l = max(l, x - d);
        r = min(r, x + d);
    }
    if (l <= r) return l;
    else return -1;
}

void solve() {
    int n; cin >> n;
    vector<LL> arr(n), adj_blank;
    for (auto &x : arr) cin >> x;
    LL diff = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) continue;
        if (i > 0 && arr[i-1] != -1) {
            diff = max(diff, abs(arr[i] - arr[i-1]));
        }
        if ((i > 0 && arr[i-1] == -1) || (i+1 < n && arr[i+1] == -1)) {
            adj_blank.emplace_back(arr[i]);
        }
    }

    if (adj_blank.empty()) {
        cout << 0 << " " << 0 << "\n"; return;
    }
    LL low = diff, high = 1e9, ans = -1, ans_num = -1;
    while (low <= high) {
        LL mid = (low + high) / 2;
        LL num = good(mid, adj_blank);
        if (num == -1) {
            low = mid + 1;
        } else {
            ans = mid, ans_num = num, high = mid - 1;
        }
    }
    cout << ans << " " << ans_num << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve(); 
    }
}

