#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL s; cin >> s;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    LL ans = 0, pre = 0;
    map<LL, int> pre_map; pre_map[0] = 1;
    for (auto x : arr) {
        pre += x;
        if (pre_map.count(pre - s) != 0) {
            ans += pre_map[pre - s];
        }
        pre_map[pre] += 1;
    }
    cout << ans << endl;
}

