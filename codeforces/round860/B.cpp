#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    map<int,int> last_day;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            last_day[x] = i;
        }
    }
    vector<int> ans(n, -1);
    for (auto [x, day] : last_day) {
        ans[day] = x;
    }
    if (*min_element(ans.begin(), ans.end()) == -1) {
        cout << -1 << "\n";
    } else {
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



