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
        bool good = true;
        for (int i = 0; i < n; i += 2) {
            good = good && (arr[i] % 2 == arr[0] % 2);
        }
        for (int i = 1; i < n; i += 2) {
            good = good && (arr[i] % 2 == arr[1] % 2);
        }
        cout << (good? "YES\n" : "NO\n");
    }
}

