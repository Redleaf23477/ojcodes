#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL S, X; cin >> S >> X;
    LL ans = 0;
    while (S > 0) {
        ans += 1;
        S /= X;
    }
    cout << ans << "\n";
}

