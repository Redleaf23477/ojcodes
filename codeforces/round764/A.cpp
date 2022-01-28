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
        cout << *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end()) << "\n";
    }
}

