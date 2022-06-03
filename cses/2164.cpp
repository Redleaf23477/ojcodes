#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int f(int n, int k) {
    if (n == 1) return 1;
    int bye = n / 2;
    if (k <= bye) {
        return 2 * k;
    }
    if (n % 2 == 0) {
        return 2 * f(n - bye, k - bye) - 1;
    } else {
        int ans = f(n - bye, k - bye);
        if (ans == 1) return n;
        else return (ans - 1) * 2 - 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        cout << f(n, k) << "\n";
    }
}

