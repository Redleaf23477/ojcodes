#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<bool> dp(x + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int j = x; j >= 0; j--) {
            dp[j] = false;
            if (a <= j && dp[j - a]) dp[j] = true;
            if (b <= j && dp[j - b]) dp[j] = true;
        }
    }
    cout << (dp[x]? "Yes\n" : "No\n");
}

