#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, P, l, t; cin >> n >> P >> l >> t;
    LL task_num = (n + 6) / 7;

    auto good = [&](LL attend) {
        LL task_done = min(2 * attend, task_num);
        LL my_point = l * attend + t * task_done;
        return my_point >= P;
    };

    LL low = 1, high = n, mid, ans = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (good(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }
    cout << n - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

