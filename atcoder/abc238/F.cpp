#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int,int>> arr(n);
    for (auto &[p, q] : arr) cin >> p;
    for (auto &[p, q] : arr) cin >> q;
    sort(arr.begin(), arr.end());

    vector<vector<int>> bigger(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        bigger[i][0] = (arr[i].second > arr[0].second);
        for (int j = 1; j <= i; j++) {
            bigger[i][j] = bigger[i][j - 1] + (arr[i].second > arr[j].second);
        }
    }

    cerr << "arr: " << endl;
    for (auto [p, q] : arr) cerr << q << " ";
    cerr << endl;
    /*
    cerr << "bigger: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cerr << bigger[i][j] << " ";
        }
        cerr << endl;
    }
    */

    // dp[prefix][max element][cnt]
    vector<vector<vector<LL>>> dp(n, vector<vector<LL>>(n + 1, vector<LL>(k + 1, 0)));
    for (int i = 0; i < n; i++) {
        // directly select arr[i] as the first element
        if (bigger[i][i] + 1 <= k) dp[i][arr[i].second][bigger[i][i] + 1] = 1;
        // transfer from j to i where maximum is bigger than itself
        for (int mx = arr[i].second + 1; mx <= n; mx++) {
            bool smaller = false;
            for (int j = 0; j < i; j++) {
                if (arr[j].second < arr[i].second) {
                    if (smaller) continue;
                    smaller = true;
                }
                int common = bigger[(arr[i].second < arr[j].second? i : j)][j] + (arr[i].second > arr[j].second);
                int more = bigger[i][i] - common + 1;
                for (int cnt = more; cnt <= k; cnt++) {
                    dp[i][mx][cnt] = (dp[i][mx][cnt] + dp[j][mx][cnt - more]) % MOD;
                }
            }
        }
    }

    /*
    cerr << "dp: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            ans += dp[i][j][k];
        }
    }
    cout << ans % MOD << "\n";
}

