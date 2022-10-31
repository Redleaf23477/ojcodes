#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        if (*max_element(arr.begin(), arr.end()) == 0) {
            cout << 0 << "\n";
        } else {
            int L = 0; while (L < n && arr[L] == 0) L++;
            int R = n-1; while (R >= 0 && arr[R] == 0) R--;
            bool z = find(arr.begin() + L, arr.begin() + R + 1, 0) != arr.begin() + R + 1;
            cout << 1 + z << "\n";
        }
    }
}

