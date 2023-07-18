#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(K);
    for (auto &x : A) {
        cin >> x; x--;
    }
    vector<pair<int,int>> arr(N);
    for (auto &[x, y] : arr) cin >> x >> y;

    auto dist2 = [&](double x1, double y1, double x2, double y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        return dx * dx + dy * dy;
    };
    auto good = [&](double R) {
        for (auto [x, y] : arr) {
            bool good = false;
            for (auto i : A) {
                auto [cx, cy] = arr[i];
                if (dist2(x, y, cx, cy) <= R * R) {
                    good = true; break;
                }
            }
            if (!good) return false;
        }
        return true;
    };

    double low = 0, high = 400000, mid, ans = high;
    while (high - low >= 0.000001) {
        mid = (low + high) / 2;
        if (good(mid)) {
            high = mid, ans = mid;
        } else {
            low = mid;
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



