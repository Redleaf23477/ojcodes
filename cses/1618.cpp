#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL n; cin >> n;
    LL ans = 0;
    for (LL i = 5; i <= n; i *= 5) {
        ans += n / i;
    }
    cout << ans << "\n";
}

