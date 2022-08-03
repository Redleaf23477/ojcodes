#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL N; cin >> N;
    LL ans = 0;
    for (LL A = 1; A*A*A <= N; A++) {
        for (LL B = A; B * B <= (N / A); B++) {
            LL C = N / (A * B);
            ans += C - B + 1;
        }
    }
    cout << ans << "\n";
}

