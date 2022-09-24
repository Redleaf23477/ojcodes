#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    double exp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double p = 0;
            for (int val = 2; val <= arr[i]; val++) {
                p += 1.0 / arr[i] * min(val - 1, arr[j]) / arr[j];
            }
            exp += p;
        }
    }
    cout << fixed << setprecision(6) << exp << "\n";
}

