#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using LL = long long int;

using Seg = tuple<LL,LL>;

int main() {
    LL N, D; cin >> N >> D;
    vector<Seg> arr(N);
    for (auto &[l, r] : arr) cin >> l >> r;
    sort(arr.begin(), arr.end(), [](const Seg &lhs, const Seg &rhs) {
        return get<1>(lhs) < get<1>(rhs);
    });
    LL mx_r = 0, ans = 0;
    for (auto [l, r] : arr) {
        if (r <= mx_r || l <= mx_r && mx_r <= r) continue;
        ans += 1, mx_r = r + D - 1;
    }
    cout << ans << endl;
}
