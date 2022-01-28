#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL k; cin >> k;
    vector<LL> arr(n); 
    for (auto &x : arr) cin >> x;
    int ans = 0, ans_l, ans_r;
    LL sum = arr[0], mn = sum;
    for (int i = 0, j = 0; i < n; ) {
        if (j < i) j = i, sum = mn = arr[i];
        if (mn >= -k) {
            while (j+1 < n && sum + arr[j+1] >= -k) {
                sum += arr[j+1];
                mn = min(mn, sum);
                j++;
            }
            if (j - i + 1 > ans) {
                ans = j - i + 1;
                ans_l = i, ans_r = j;
            }
        }
        sum -= arr[i];
        mn -= arr[i];
        i++;
    }
    if (ans == 0) cout << -1 << "\n";
    else cout << ans_l + 1 << " " << ans_r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

