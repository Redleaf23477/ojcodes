#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int cnt = 0, acc = 0;
        int x, y, n; cin >> x >> y >> n;
        while (n - acc >= x) {
            acc += x + y;
            cnt += x;
        }
        if (n - acc > 0) cnt += n - acc;
        cout << 3 * cnt << "\n";
    }
}

