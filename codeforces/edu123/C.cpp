#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 5000 * 100000;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        LL x; cin >> x;
        vector<LL> arr(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        partial_sum(arr.begin(), arr.end(), arr.begin());
        vector<LL> len_max(n+1, -INF); len_max[0] = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int len = r - l + 1;
                LL val = arr[r] - arr[l-1];
                len_max[len] = max(len_max[len], val);
            }
        }
        for (int i = 0; i <= n; i++) {
            len_max[i] += x * i;
        }

        vector<LL> ans = len_max;
        for (int i = 1; i <= n; i++) ans[i] = max(ans[i], ans[i-1]);
        LL suf = ans[n];
        for (int k = n-1; k >= 0; k--) {
            suf -= x;
            ans[k] = max(ans[k], suf);
            suf = max(suf, len_max[k]);
        }

        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

