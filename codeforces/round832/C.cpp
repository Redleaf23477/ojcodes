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

        int mn_idx = min_element(arr.begin(), arr.end()) - arr.begin();

        cout << (mn_idx == 0? "Bob\n" : "Alice\n");
    }
}

