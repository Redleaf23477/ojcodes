#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 2 == 1) {
        cout << -1 << "\n"; return; 
    } else {
        int target = (sum > 0? 1 : -1);
        int prev = -1;
        vector<int> neg1_pos;
        for (int i = 0; i < n; i++) {
            if (sum != 0 && arr[i] == target && i - prev > 1) {
                neg1_pos.emplace_back(i);
                sum -= 2 * target;
                prev = i;
            }
        }

        if (sum != 0) {
            cout << -1 << "\n"; return;
        }

        int sz = n - neg1_pos.size();
        cout << sz << "\n";
        vector<int> L;
        for (int i = 0, j = 0; i < n; i++) {
            if (j < (int)neg1_pos.size() && i == neg1_pos[j]) {
                j++; continue;
            }
            L.emplace_back(i+1);
        }
        L.emplace_back(n+1);
        for (int i = 0; i+1 < (int)L.size(); i++) {
            cout << L[i] << " " << L[i+1]-1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

