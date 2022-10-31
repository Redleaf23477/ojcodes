#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL gcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL x1, y1;
    LL d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

tuple<LL,LL,LL> get_coef(LL x, LL y, LL n) {
    LL i = 0, j = 0;
    // i * x + j * y = g
    LL g = gcd(x, y, i, j);
    if (n % g != 0) {
        return make_tuple(-1, -1, -1);
    }
    i *= n / g;
    j *= n / g;

    // any solution will be (i + k * b / g, j - k * a / g)
    return make_tuple(i, j, g);
}

void solve(LL n, LL sum_a, vector<LL> const &delta, vector<LL> const &pref_delta) {
    LL x, y; cin >> x >> y;
    // i * x + j * y = n
    // (i + k * y / g) * x + (j - k * x / g) * y = n
    auto [i, j, g] = get_coef(x, y, n);
    if (g == -1) {
        cout << -1 << "\n"; return;
    }
    // cerr << " i = " << i << ", x = " << x << ", j = " << j << ", y = " << y << endl;
    // do binary search on delta
    // because I don't know how to calculate the index
    LL low = -n, high = n, mid, val = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        LL i2 = i + mid * y / g;
        LL j2 = j - mid * x / g;
        // cerr << "mid = " << mid << ", i2 = " << i2 << ", j2 = " << j2 << endl;
        if (i2 < 0) low = mid + 1;
        else if (j2 < 0) high = mid - 1;
        else {
            // update answer
            if (i2 * x == n) val = max(val, sum_a);
            else val = max(val, sum_a + pref_delta[n - i2 * x - 1]);
            // update range
            if (i2 * x == n) high = mid - 1;
            else if (delta[n - i2 * x - 1] < 0) low = mid + 1;
            else high = mid - 1;
        }
    }
    cout << val << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> A(n), B(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
        D[i] = B[i] - A[i];
    }
    LL sum_a = accumulate(A.begin(), A.end(), 0ll);
    sort(D.begin(), D.end(), greater<LL>());
    vector<LL> acc_D = D;
    for (int i = 1; i < n; i++) acc_D[i] += acc_D[i-1];

    int q; cin >> q;
    while (q--) {
        solve(n, sum_a, D, acc_D);
    }
}

