#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<int> arr(1, 1);
    for (int i = 0; i < N; i++) {
        for (auto x : arr) cout << x << " ";
        cout << "\n";
        for (int i = arr.size() - 1; i > 0; i--) {
            arr[i] += arr[i-1];
        }
        arr.emplace_back(1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



