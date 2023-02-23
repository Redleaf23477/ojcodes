#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for (auto &[x, y] : arr) {
        cin >> x >> y;
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = arr[i].first - arr[j].first;
            double dy = arr[i].second - arr[j].second;
            ans = max(ans, sqrt(dx * dx + dy * dy));
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

