#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> table;
void build_table() {
    while (table.empty() || table.back() < 1000000) {
        int x = table.size();
        table.emplace_back(x * (x-1) / 2);
    }
}

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    // i == n
    if (table[n] == k) {
        cout << "YES\n";
        for (int x = 0; x < n; x++) cout << 1 << " ";
        cout << "\n";
        return;
    }
    // i == n-1
    if (table[n-1] == k) {
        cout << "YES\n";
        for (int x = 0; x < n-1; x++) cout << 1 << " ";
        cout << -1 << "\n";
        return;
    }
    // the rest
    for (int i = 2; i <= n-2; i++) {
        int pos = table[i];
        int neg = k - pos;
        auto it = lower_bound(table.begin(), table.end(), neg);
        int j = it - table.begin();
        if (it != table.end() && *it == neg && j == n - i) {
            cout << "YES\n";
            for (int x = 0; x < i; x++) cout << 1 << " ";
            for (int x = 0; x < j; x++) cout << -1 << " ";
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    build_table();
    while (T--) {
        solve();
    }
}



