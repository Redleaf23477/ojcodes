#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL n, m, x, y; cin >> n >> m >> x >> y;
    vector<LL> arr(m);
    for (auto &x : arr) cin >> x;
    LL ans = 0, left = 0;
    // first
    if (!arr.empty()) {
        if (arr.front() > x) {
            LL delta = arr.front() - 1;
            LL a = x, b = min(x, y - x);
            ans += delta / (a + b + 2) * 2;
            LL rem = delta % (a + b + 2);
            if (rem <= a) {
                left = rem;
            } else {
                ans += 1;
                left = rem - a - 1;
            }
        } else {
            left = arr.front() - 1;
        }
    }
    // middle
    for (int i = 1; i < m; i++) {
        LL delta = arr[i] - arr[i-1] - 1;
        LL a = min(x, y - left), b = min(x, y - a);
        ans += delta / (a + b + 2) * 2;
        LL rem = delta % (a + b + 2);
        if (rem <= a) {
            left = rem;
        } else {
            ans += 1;
            left = rem - a - 1;
        }
    }
    // last
    if (!arr.empty()) {
        LL delta = n - arr.back();
        LL a = min(x, y - left), b = min(x, y - a);
        ans += delta / (a + b + 2) * 2;
        LL rem = delta % (a + b + 2);
        if (rem > a) {
            ans += 1;
        }
    } else {
        LL delta = n;
        LL a = x, b = min(x, y - x);
        ans += delta / (a + b + 2) * 2;
        LL rem = delta % (a + b + 2);
        if (rem > a) {
            ans += 1;
        }
    }

    cout << ans << "\n";
}

