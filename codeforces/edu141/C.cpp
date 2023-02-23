#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL m; cin >> m;
    vector<pair<LL,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    // base
    int kill = 0;
    LL acc = 0;
    for (auto [tim, win] : arr) {
        if (acc + tim <= m) {
            kill++, acc += tim;
        } else {
            break;
        }
    }

    // adjust
    int adjust = 0;
    if (kill != 0 && kill != n) {
        int kidx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i].second == kill) {
                kidx = i; break;
            }
        }
        if (m - acc + arr[kill-1].first >= arr[kidx].first) {
            adjust = -1;
        }
    }

    // cerr << "kill = " << kill << ", adj = " << adjust << endl;

    // print result
    cout << n - kill + adjust + 1 << "\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

