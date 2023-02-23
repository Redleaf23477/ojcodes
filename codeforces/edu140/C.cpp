#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

/*
bool validate(vector<vector<int>> &arr, int n) {
    // rule0: arr[i][i] is always 1
    for (int i = 0; i < n; i++) {
        if (arr[i][i] == 2) return false;
        else if (arr[i][i] == 0) arr[i][i] = 1;
    }
    // rule1: for any 1, left and down 0 becomes 1, cannot meet 2
    //   1-1: do left
    for (int r = 0; r < n; r++) {
        bool meet1 = false;
        for (int c = n-1; c >= r; c--) {
            if (!meet1) {
                if (arr[r][c] == 1) meet1 = true;
            } else {
                if (arr[r][c] == 2) return false;
                else if (arr[r][c] == 0) arr[r][c] = 1;
            }
        }
    }
    //   1-2: do down
    for (int c = 0; c < n; c++) {
        bool meet1 = false;
        for (int r = 0; r < c; r++) {
            if (!meet1) {
                if (arr[r][c] == 1) meet1 = true;
            } else {
                if (arr[r][c] == 2) return false;
                else if (arr[r][c] == 0) arr[r][c] = 1;
            }
        }
    }
    // rule2: for any 2, right and up 0 becomes 2, cannot meet 1
    //   2-1: do right
    for (int r = 0; r < n; r++) {
        bool meet2 = false;
        for (int c = r; c < n; c++) {
            if (!meet2) {
                if (arr[r][c] == 2) meet2 = true;
            } else {
                if (arr[r][c] == 1) return false;
                else if (arr[r][c] == 0) arr[r][c] = 2;
            }
        }
    }
    //   2-2: do up
    for (int c = 0; c < n; c++) {
        bool meet2 = false;
        for (int r = c; r >= 0; r--) {
            if (!meet2) {
                if (arr[r][c] == 2) meet2 = true;
            } else {
                if (arr[r][c] == 1) return false;
                else if (arr[r][c] == 0) arr[r][c] = 2;
            }
        }
    }
    return true;
}

vector<int> get_method(vector<vector<int>> &arr, int n) {
    vector<int> method;
    int r = 0, c = 0;
    while (r < n && c < n) {
        // move right until meet first non 1
        while (r < n && arr[r][c] == 1) r++;
        if (r == n) break;
        // check arr[r][c] is 0 or 2
        method.emplace_back(arr[r][c]);
        // move down until meet first 1
        while (c < n && arr[r][c] != 1) c++;
    }
    return method;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    if (!validate(arr, n)) {
        cout << 0 << "\n";
        return;
    }
    vector<int> method = get_method(arr, n);
    // run dp
    LL ans = 2;
    for (auto m : method) {
        if (m == 0) ans = ans * 2 % MOD;
    }
    cout << ans << "\n";
}
*/

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    // dp[r][start_idx_of_tailing_consecutive_numbers]
    vector<vector<LL>> dp(n, vector<int>(n, 0));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

