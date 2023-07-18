#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL N, A, B; cin >> N >> A >> B;
    LL AB = lcm(A, B);
    LL ans = (1 + N) * N / 2;
    ans -= (1 + N / A) * (N / A) / 2 * A;
    ans -= (1 + N / B) * (N / B) / 2 * B;
    ans += (1 + N / AB) * (N / AB) / 2 * AB;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



