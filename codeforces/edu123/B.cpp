#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            for (auto x : arr) cout << x << " ";
            cout << "\n";
            if (i != n-1) swap(arr[n-1-i], arr[n-2-i]);
        }
    }
}

