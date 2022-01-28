#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int ans = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > ans) ans = arr[i];
        else break;
    }
    cout << ans << "\n";
}

