#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    vector<char> ch;
    vector<int> cnt;
    for (auto x : str) {
        if (ch.empty() || ch.back() != x) {
            ch.emplace_back(x), cnt.emplace_back(1);
        } else {
            cnt.back() += 1;
        }
    }
    for (size_t i = 0; i < ch.size(); i++) {
        if (i + 1 < ch.size() && ch[i] < ch[i+1]) {
            // highlight
            for (int j = 0; j < cnt[i] * 2; j++) cout << ch[i];
        } else {
            while (cnt[i]--) cout << ch[i];
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

