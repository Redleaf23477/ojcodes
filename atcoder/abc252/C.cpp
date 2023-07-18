#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int run(int num, vector<string> &arr, int N) {
    int tim = 0;
    for (int d = 0; d < 10; d++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i][d] == num + '0') {
                cnt++;
            }
        }
        if (cnt > 0) {
            tim = max(tim, d + (cnt - 1) * 10);
        }
    }
    return tim;
}

void solve() {
    int N; cin >> N;
    vector<string> arr(N);
    for (auto &s : arr) cin >> s;
    int ans = 10 * N;
    for (int num = 0; num < 10; num++) {
        ans = min(ans, run(num, arr, N));
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



