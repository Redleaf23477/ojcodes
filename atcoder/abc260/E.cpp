#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    vector<pair<int,int>> arr(N);
    for (auto &[l, r] : arr) cin >> l >> r;
    sort(arr.begin(), arr.end());
    vector<int> acc(M + 2, 0);
    int stop = arr[0].second, max_r = arr[0].first;
    for (int i = 1, j = 0; i <= stop; i++) {
        while (j < N && i > arr[j].first) {
            stop = min(stop, arr[j].second);
            max_r = max(max_r, arr[j].second);
            j++;
        }
        int len_lb = max(max_r, arr.back().first) - i + 1;
        int len_ub = M - i + 1;
        acc[len_lb] += 1, acc[len_ub + 1] -= 1;
    }
    partial_sum(acc.begin(), acc.end(), acc.begin());
    for (int i = 1; i <= M; i++) {
        cout << acc[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



