#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    constexpr int INF = 1e9+9;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n), odd_suf(n+1), even_suf(n+1);
        for (auto &x : arr) cin >> x;
        odd_suf.back() = even_suf.back() = INF;
        for (int i = n-1; i >= 0; i--) {
            if (arr[i] % 2 == 0) {
                even_suf[i] = min(arr[i], even_suf[i+1]);
                odd_suf[i] = odd_suf[i+1];
            } else {
                even_suf[i] = even_suf[i+1];
                odd_suf[i] = min(arr[i], odd_suf[i+1]);
            }
        }
        bool ans = true;
        for (int i = 0; i < n && ans; i++) {
            if (arr[i] % 2 == 0) {
                if (even_suf[i+1] < arr[i]) ans = false;
            } else {
                if (odd_suf[i+1] < arr[i]) ans = false;
            }
        }
        cout << (ans? "Yes\n" : "No\n");
    }
}

