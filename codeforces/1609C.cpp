#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

vector<bool> build_prime(int N) {
    vector<bool> arr(N, true);
    for (int i = 2; i < N/i; i++) {
        if (arr[i]) {
            for (int j = i*i; j < N; j += i) {
                arr[j] = false;
            }
        }
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    vector<bool> is_prime = build_prime(1000001);
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;

        LL ans = 0;
        for (int i = 0; i < k; i++) {
            LL consecutive_ones = 0, prev = 1, prev_cnt = 0;
            for (int j = i; j < n; j += k) {
                if (arr[j] == 1) {
                    if (prev != 1 && is_prime[prev]) {
                        ans += prev_cnt + 1;
                    }
                    consecutive_ones += 1;
                } else {
                    if (is_prime[arr[j]]) ans += consecutive_ones;
                    prev_cnt = consecutive_ones;
                    prev = arr[j];
                    consecutive_ones = 0;
                }
            }
        }
        cout << ans << '\n';
    }
}

