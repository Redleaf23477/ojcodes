#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int N; cin >> N;
    vector<int> arr(N);
    for (auto &x : arr) cin >> x;
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        int x = arr[i];
        int dist = (x + N - i) % N;
        ans[dist] += 1;
        ans[(dist + 1) % N] += 1;
        ans[(dist - 1 + N) % N] += 1;
    }
    cout << *max_element(ans.begin(), ans.end()) << "\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}