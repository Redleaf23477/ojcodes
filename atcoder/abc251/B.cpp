#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    unordered_set<string> vis;
    int ans = 0, best = -1;
    for (int i = 1; i <= N; i++) {
        string str; cin >> str;
        int score; cin >> score;
        if (vis.count(str) != 0) continue;
        vis.insert(str);
        if (score > best) best = score, ans = i;
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



