#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    vector<int> H(3), W(3);
    for (auto &x : H) cin >> x;
    for (auto &x : W) cin >> x;
    int ans = 0;
    for (int a = 1; a < H[0] && a < W[0]; a++) {
        for (int b = 1; a + b < H[0] && b < W[1]; b++) {
            for (int c = 1; c < H[1] && a + c < W[0]; c++) {
                for (int d = 1; c + d < H[1] && b + d < W[1]; d++) {
                    int e = H[0] - a - b;
                    int f = H[1] - c - d;
                    int g = W[0] - a - c;
                    int h = W[1] - b - d;
                    int i = H[2] - g - h;
                    if (e <= 0 || f <= 0 || g <= 0 || h <= 0 || i <= 0) {
                        continue;
                    }
                    if (W[2] - e - f == i) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



