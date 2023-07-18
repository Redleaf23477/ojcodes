#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> arr(N + 1), pos(N + 1);
    iota(arr.begin(), arr.end(), 0);
    iota(pos.begin(), pos.end(), 0);
    while (Q--) {
        int x; cin >> x;
        if (pos[x] == N) {
            swap(arr[pos[x]], arr[pos[x] - 1]);
            pos[arr[pos[x]]] = pos[x];
            pos[arr[pos[x] - 1]] = pos[x] - 1;
        } else {
            swap(arr[pos[x]], arr[pos[x] + 1]);
            pos[arr[pos[x]]] = pos[x];
            pos[arr[pos[x] + 1]] = pos[x] + 1;
        }
    }
    for (int i = 1; i <= N; i++) cout << arr[i] << " ";
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



