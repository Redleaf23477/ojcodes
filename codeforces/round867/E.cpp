#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    if (n % 2 == 1) {
        cout << -1 << "\n"; return;
    }

    vector<int> cnt(26, 0);
    for (auto ch : str) {
        cnt[ch - 'a']++;
    }
    if (*max_element(cnt.begin(), cnt.end()) > n / 2) {
        cout << -1 << "\n"; return;
    }

    vector<int> bad(26, 0);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] == str[n - i - 1]) {
            bad[str[i] - 'a']++;
        }
    }

    int ans = 0;
    priority_queue<int> pq(bad.begin(), bad.end());
    while (!pq.empty()) {
        if (pq.size() >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans += b;
            pq.emplace(a - b);
        } else {
            ans += pq.top(); pq.pop();
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



