#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL N; cin >> N;
    LL ans = -1; 
    auto sum = [](LL a, LL b) {
        return (a + b) * (a * a + b * b);
    };
    for (LL a = 0; a <= 1'000'000; a++) {
        LL low = 0, high = 1'000'000, mid, b = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (sum(a, mid) >= N) {
                b = mid, high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans = (ans == -1? sum(a, b) : min(ans, sum(a, b)));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



