#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    vector<int> ans(n, -1);

    int normal = 0, rev = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            if (rev > 0) {
                ans[i] = 2;
                rev--;
            } else {
                ans[i] = 1;
                normal++;
            }
        } else {
            if (normal > 0) {
                ans[i] = 1;
                normal--;
            } else {
                ans[i] = 2;
                rev++;
            }
        }
    }

    if (normal != 0 || rev != 0) {
        cout << -1 << "\n";
        return;
    }

    // fix color
    bool use_1 = (find(ans.begin(), ans.end(), 1) != ans.end());
    bool use_2 = (find(ans.begin(), ans.end(), 2) != ans.end());
    if (!use_1 || !use_2) {
        cout << 1 << "\n";
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << "\n";
    } else {
        cout << 2 << "\n";
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



