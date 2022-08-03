#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool is_palindrome(int i, int s, int ins) {
    if (i < 4) return false;

    int mask = ((s << 1) + ins) & 63;
    int arr[6];
    for (int j = 0; j < 6; j++, mask >>= 1) {
        arr[5-j] = (mask & 1);
    }
    bool len6 = (i >= 5) && (arr[0] == arr[5] && arr[1] == arr[2] && arr[3] == arr[4]);
    bool len5_l = arr[0] == arr[4] && arr[1] == arr[3];
    bool len5_r = (i >= 5) && (arr[1] == arr[5] && arr[2] == arr[4]);
    return len6 || len5_l || len5_r;
}

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    const int M = (1 << 6) - 1;

    if (n < 5) { cout << "POSSIBLE\n"; return; }

    vector<vector<bool>> dp(n, vector<bool>(64, false));

    // i = 0
    if (str[0] == '0') dp[0][0] = true;
    else if (str[0] == '1') dp[0][1] = true;
    else if (str[0] == '?') dp[0][0] = dp[0][1] = true;
    // i = 1 - n-1
    for (int i = 1; i < n; i++) for (int s = 0; s < 64; s++) {
        if (dp[i-1][s] == false) continue;

        if (str[i] == '0') {
            if (!is_palindrome(i, s, 0)) dp[i][(s << 1) & M] = true;
        } else if (str[i] == '1') {
            if (!is_palindrome(i, s, 1)) dp[i][((s << 1) + 1) & M] = true;
        } else {
            if (!is_palindrome(i, s, 0)) dp[i][(s << 1) & M] = true;
            if (!is_palindrome(i, s, 1)) dp[i][((s << 1) + 1) & M] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        cerr << "dp[" << i << "]: ";
        for (int s = 0; s < 64; s++) {
            if (dp[i][s]) {
                cerr << bitset<6>(s).to_string() << ": " << dp[i][s] << endl;
            }
        }
    }

    for (int s = 0; s < 64; s++) {
        if (dp[n-1][s]) { cout << "POSSIBLE\n"; return; }
    }

    cout << "IMPOSSIBLE\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

