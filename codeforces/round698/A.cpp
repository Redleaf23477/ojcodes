#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> cnt(2*n, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; cnt[x]++;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
    cout.flush();
    return 0;
}

