#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, K; cin >> N >> K;
    vector<vector<int>> arr(K);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr[i % K].emplace_back(x);
    }
    for (int i = 0; i < K; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    vector<int> merged(N);
    for (int s = 0, i = 0, j = 0; s < N; s++) {
        merged[s] = arr[i][j];
        if (++i == K) {
            i = 0, j++;
        }
    }
    bool good = true;
    for (int i = 1; i < N; i++) {
        if (merged[i] < merged[i-1]) {
            good = false;
        }
    }
    cout << (good? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



