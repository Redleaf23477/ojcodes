#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void relabel(vector<int> &arr) {
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());
    auto it = unique(tmp.begin(), tmp.end());
    tmp.erase(it, tmp.end());
    for (auto &x : arr) x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    relabel(arr);

    LL ans = 0;
    vector<int> cnt(n, 0);
    for (int i = 0, j = -1, distinct = 0; i < n; i++) {
        for (; j+1 < n; j++) {
            if (cnt[arr[j+1]] == 0) {
                if (distinct + 1 > k) break;
                distinct += 1;
            }
            cnt[arr[j+1]] += 1;
        }
        ans += j - i + 1;
        if (cnt[arr[i]] == 1) distinct -= 1;
        cnt[arr[i]] -= 1;
    }
    cout << ans << "\n";
}

