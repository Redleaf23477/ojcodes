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
        sort(arr.begin(), arr.end());
        if (arr.front() == arr.back()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << arr.back();
            for (int i = 0; i < n-1; i++) {
                cout << " " << arr[i];
            }
            cout << "\n";
        }
    }
}

