#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int solve(int n, int k, string const &str, char target) {
    vector<int> acc(n+1, 0);
    for (int i = 1; i <= n; i++) {
        acc[i] = acc[i-1] + (str[i-1] != target);
    }
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        int r = upper_bound(acc.begin(), acc.end(), k + acc[l-1]) - acc.begin();
        ans = max(ans, r - l);
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    string str; cin >> str;
    cout << max(solve(n, k, str, 'a'), solve(n, k, str, 'b')) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



