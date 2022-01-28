#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL n, LL k, LL m) {
    LL ans = (n%m != 0);
    while (k > 0) {
        if (k % 2 == 1) ans = ans * n % m;
        n = n * n % m;
        k /= 2;
    }
    return ans;
}

LL up(LL n, LL k) {
    // let n = a * 10^b, in scientific expression
    // n^k = (a * 10^b)^k, we only need to care about a^k
    // lg(a^k) = k * lg(a) = lg(ANS)

    double b_10 = 1;
    while (b_10 * 10 < n) b_10 *= 10;

    cerr << "b_10 = " << b_10 << endl;

    double a = (double)n / b_10;
    double lg_ak = k * log10(a);
    double ans = pow(10, lg_ak) * 100;

    cerr << "a = " << a << endl;
    cerr << "lg_ak = " << lg_ak << endl;
    cerr << "ans = " << ans << endl;

    return ans;
}

LL down(LL n, LL k) {
    return fastpw(n, k, 1000);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL n, k; cin >> n >> k;
        cout << up(n, k) << "..."
            << setw(3) << setfill('0') << down(n, k) << "\n";
    }
}

