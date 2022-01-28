#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;
    LL ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            ans += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout << ans << "\n";
}

