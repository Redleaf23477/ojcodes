#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    int x3, y3; cin >> x3 >> y3;
    vector<tuple<int,int>> arr {{x1, y1}, {x2, y2}, {x3, y3}};
    sort(arr.begin(), arr.end());
    do {
        auto [x0, y0] = arr[0];
        auto [x1, y1] = arr[1];
        auto [x2, y2] = arr[2];
        if (x0 == x1 && y0 == y2) {
            cout << "NO\n";
            return;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    cout << "YES\n"; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

