#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<LL> arr(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    partial_sum(arr.begin(), arr.end(), arr.begin());
    while (q--) {
        int l, r; cin >> l >> r;
        cout << arr[r] - arr[l-1] << "\n";
    }
}

