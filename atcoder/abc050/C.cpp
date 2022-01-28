#include <bits/stdc++.h>
using namespace std;

int run(const vector<int> &cnt, const int n) {
    constexpr int MOD = 1e9+7;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            if (cnt[i] != 0) return 0;
        }
        for (int i = 1; i < n; i += 2) {
            if (cnt[i] != 2) return 0;
        }
    } else {
        if (cnt[0] != 1) return 0;
        for (int i = 2; i < n; i += 2) {
            if (cnt[i] != 2) return 0;
        }
        for (int i = 1; i < n; i += 2) {
            if (cnt[i] != 0) return 0;
        }
    }
    int ans = 1;
    for (int i = 0; i < n/2; i++) {
        ans = ans * 2 % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x] += 1;
    }
    cout << run(cnt, n) << endl; 
}
