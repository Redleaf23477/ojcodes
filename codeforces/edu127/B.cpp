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
        sort(arr.begin(), arr.end());
        bool ans = arr.back() - arr.front() < n + 2;
        cout << (ans? "YES\n" : "NO\n");
    }
}

