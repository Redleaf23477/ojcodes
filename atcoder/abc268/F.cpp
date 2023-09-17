#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int N; cin >> N;
    vector<string> arr(N);
    for (auto &x : arr) cin >> x;
    vector<int> x_cnt(N, 0);
    vector<LL> digit_sum(N, 0);
    for (int i = 0; i < N; i++) {
        for (auto &ch : arr[i]) {
            if (ch == 'X') x_cnt[i]++;
            else digit_sum[i] += (ch - '0');
        }
    }

    vector<int> sort_seq(N);
    iota(sort_seq.begin(), sort_seq.end(), 0);
    sort(sort_seq.begin(), sort_seq.end(), [&](int lhs, int rhs) {
        return x_cnt[lhs] * digit_sum[rhs] > x_cnt[rhs] * digit_sum[lhs];
    });

    LL ans = 0, d_sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        string &str = arr[sort_seq[i]];
        for (int j = str.size() - 1; j >= 0; j--) {
            char ch = str[j];
            if (ch == 'X') ans += d_sum;
            else d_sum += ch - '0';
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}