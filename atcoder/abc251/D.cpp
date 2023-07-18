#include <bits/stdc++.h>
using namespace std;
using LL = long long int;


void solve() {
    int n; cin >> n;
    vector<int> arr;
    for (int i = 1; i < 100; i++) {
        arr.emplace_back(i);
        arr.emplace_back(i * 100);
        arr.emplace_back(i * 10000);
    }
    arr.emplace_back(1000000);
    cout << arr.size() << "\n";
    for (auto x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



