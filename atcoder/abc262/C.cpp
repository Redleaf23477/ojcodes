#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> good;
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; arr[i]--;
        if (arr[i] == i) {
            good.emplace_back(i);
        }
    }
    LL ans = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == i) {
            // j > i s.t. arr[j] == j
            ans += good.end() - upper_bound(good.begin(), good.end(), i);
        } else {
            // j == arr[i], arr[j] == i and j > i
            ans += (arr[arr[i]] == i && arr[i] > i);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



