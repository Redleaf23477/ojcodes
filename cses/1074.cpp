#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    LL med = arr[arr.size() / 2];
    LL ans = 0;
    for (auto x : arr) {
        ans += abs(x - med);
    }
    cout << (LL)ans << "\n";
}

