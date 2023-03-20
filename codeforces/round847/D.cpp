#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        if (s.count(arr[i]-1) == 0) {
            s.insert(arr[i]);
        } else {
            auto it = s.find(arr[i]-1);
            s.erase(it);
            s.insert(arr[i]);
        }
    }
    cout << s.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



