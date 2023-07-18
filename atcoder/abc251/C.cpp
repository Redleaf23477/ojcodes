#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, W; cin >> N >> W;
    vector<int> arr(N);
    for (auto &x : arr) cin >> x;
    arr.emplace_back(0), N += 1;
    arr.emplace_back(0), N += 1;
    vector<bool> vis(W + 1, false);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum <= W) {
                    vis[sum] = true;
                }
            }
        }
    }

    cout << accumulate(vis.begin(), vis.end(), 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



