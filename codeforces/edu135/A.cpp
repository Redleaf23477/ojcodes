#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<tuple<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        auto &[cnt, color] = arr[i];
        cin >> cnt;
        color = i + 1;
    }
    sort(arr.begin(), arr.end(), greater<tuple<int,int>>());
    while (arr.size() > 1) {
        int bye = get<0>(arr.back()); arr.pop_back();
        get<0>(arr.back()) -= bye;
    }
    cout << get<1>(arr.back()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

