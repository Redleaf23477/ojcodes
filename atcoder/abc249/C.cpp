#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int calc(int mask, int k, vector<int> &arr) {
    int ans = 0;
    for (int ch = 0; ch < 26; ch++) {
        int cnt = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            if ((mask >> i) & 1) {
                if ((arr[i] >> ch) & 1) {
                    cnt++;
                }
            }
        }
        if (cnt == k) ans++;
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n, 0);
    for (auto &mask : arr) {
        string str; cin >> str;
        for (auto ch : str) {
            mask |= (1 << (ch - 'a'));
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans = max(ans, calc(i, k, arr));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



