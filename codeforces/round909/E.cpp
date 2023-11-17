#include <bits/stdc++.h>
using namespace std;
using LL = long long;

using IT = vector<int>::iterator;
bool sorted(IT L, IT R) {
    auto it = L; it++;
    while (it != R) {
        if (*it < *(it - 1)) return false;
        it++;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    auto it = min_element(arr.begin(), arr.end());
    if (!sorted(it, arr.end())) {
        cout << -1 << "\n";
    } else {
        cout << it - arr.begin() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

