#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n), sum(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    partial_sum(arr.begin(), arr.end(), sum.begin());

    if (n == 1) {
        cout << sum[0] + sum[0] << "\n";
    } else if (n == 2) {
        cout << sum[1] + arr[1] - arr[0] << "\n";
    } else if (sum[n-2] == arr[n-1] || sum[n-3] >= arr[n-1]) {
        cout << sum[n-1] << "\n";
    } else if (sum[n-2] > arr[n-1]) {
        cout << sum[n-1] << "\n";
    } else if (sum[n-2] < arr[n-1]) {
        cout << sum[n-1] + arr[n-1] - sum[n-2] << "\n";
    } else {
        assert(false); // unreachable
    }
}

