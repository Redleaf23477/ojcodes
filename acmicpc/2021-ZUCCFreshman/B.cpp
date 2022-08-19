#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        double n, m, k; cin >> n >> m >> k;
        double h = k / m;
        cout << fixed << setprecision(10) << (n-1) * h << "\n";
    }
}

