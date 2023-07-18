#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for (auto &[x, y] : arr) cin >> x >> y;
    string s; cin >> s;
    map<int, int> min_right, max_left;
    for (int i = 0; i < n; i++) {
        auto [x, y] = arr[i];
        if (s[i] == 'L') {
            if (max_left.count(y) == 0) max_left[y] = 0;
            max_left[y] = max(max_left[y], x);
        } else {
            if (min_right.count(y) == 0) min_right[y] = 1e9;
            min_right[y] = min(min_right[y], x);
        }
    }
    for (auto [y, x] : min_right) {
        if (max_left.count(y) != 0) {
            int x2 = max_left[y];
            if (x < x2) { cout << "Yes\n"; return; }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



