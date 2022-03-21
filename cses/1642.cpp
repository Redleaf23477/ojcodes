#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL sum; cin >> sum;
    vector<LL> arr(n); 
    for (auto &x : arr) cin >> x;
    map<LL, vector<T>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mp[arr[i] + arr[j]].emplace_back(i, j);
        }
    }

    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        for (int j = i + 1; j < n && !ans; j++) {
            LL s = arr[i] + arr[j];
            if (mp.count(sum - s) != 0) {
                auto &vec = mp[sum - s];
                auto it = upper_bound(vec.begin(), vec.end(), T(j, n));
                if (it != vec.end()) {
                    auto [k, l] = *it;
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << "\n";
                    ans = true;
                }
            }
        }
    }
    if (!ans) cout << "IMPOSSIBLE\n";
}
