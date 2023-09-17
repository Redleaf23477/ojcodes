#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    vector<int> arr(5);
    for (auto &x : arr) cin >> x;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int add = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) add = 0;
        }
        ans += add;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}