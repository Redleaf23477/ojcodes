#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL W, L; cin >> L >> W;
    vector<LL> arr(n); 
    for (auto &x : arr) cin >> x;
    arr.emplace_back(L);
    LL ans = 0, l = 0;
    for (auto x : arr) {
        LL len = x - l;
        if (len >= 0) {
            ans += (len + W - 1) / W;
        }
        l = x + W;
    }
    cout << ans << "\n";
}

