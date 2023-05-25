#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> pos_in_arr(n+1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos_in_arr[x] = i + 1;
    }
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int d = abs(i - pos_in_arr[i]);
        g = gcd(g, d);
    }
    cout << g << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



