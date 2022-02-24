#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        int i, j;
        for (i = 0; i < n; i++) {
            if (arr[i] != i+1) break;
        }
        if (i != n) {
            j = find(arr.begin(), arr.end(), i+1) - arr.begin();
            reverse(arr.begin() + i, arr.begin() + j + 1);
        }
        for (auto x : arr) cout << x << " ";
        cout << "\n";
    }
}

