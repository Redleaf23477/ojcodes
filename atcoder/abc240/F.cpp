#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// a b c d e
// a ab abc abcd abcde
// a aab aaabbc aaaabbbccd

void solve() {
    int n, M; cin >> n >> M;
    vector<pair<LL,LL>> arr(n);
    for (auto &[val, cnt] : arr) {
        cin >> val >> cnt;
    }
    LL ans = -1e18, acc = 0, sum = 0;
    for (auto [val, cnt] : arr) {
        // best
        ans = max(ans, sum + val);
        if (acc > 0 && acc + val * cnt < 0) {
            LL d = -1 * acc / val;
            ans = max(ans, sum + acc * d + val * (1 + d) * d / 2);
        }
        // end
        sum += acc * cnt + val * (1 + cnt) * cnt / 2;
        acc += val * cnt;
        ans = max(ans, sum);
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

