#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<tuple<int,int,int>> arr(n, make_tuple(0, 0, 0));
    for (auto &[len, diff, cnt] : arr) {
        string str; cin >> str;
        len = str.size() % 2;
        for (auto ch : str) {
            diff |= 1 << (ch - 'a');
            cnt ^= 1 << (ch - 'a');
        }
    }
    LL ans = 0;
    for (int ban = 0; ban < 26; ban++) {
        vector<map<int,int>> data(2);
        for (auto [len, diff, cnt] : arr) {
            if ((diff >> ban) & 1) continue;
            data[len][cnt] += 1;
        }
        for (auto [len, diff, cnt] : arr) {
            if ((diff >> ban) & 1) continue;
            int key = ((1 << 26) - 1) ^ cnt ^ (1 << ban);
            if (data[len^1].count(key) != 0) {
                ans += data[len^1][key];
            }
        }
    }
    cout << ans / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



