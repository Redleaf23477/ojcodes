#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

double power(double x, int p) {
    double ans = 1;
    while (p--) {
        ans *= x;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;

    double exp = 0;

    for (int mx = 1; mx <= k; mx++) {
        // prob = (mx / k) ^ n - (1 - (mx-1) / mx ^ n / (mx / k ^ n))
        double p1 = static_cast<double>(mx) / static_cast<double>(k);
        double p2 = static_cast<double>(mx - 1) / static_cast<double>(k);
        double prob = power(p1, n) - power(p2, n);
        exp += mx * prob;
    }


    cout << fixed << setprecision(6) << exp << "\n";
}

