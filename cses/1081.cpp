#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> vis(*max_element(arr.begin(), arr.end()) + 1, 0);
    for (auto x : arr) vis[x] += 1;
    int ans = 1;
    for (int g = 2; g < vis.size(); g++) {
        int cnt = 0;
        for (int x = g; x < vis.size(); x += g) {
            cnt += vis[x];
        }
        if (cnt > 1) ans = g;
    }
    cout << ans << "\n";
}