// will log work???
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL sum(LL D) {
    return (2 * D * D * D * D * D * D + 6 * D * D * D * D * D + 5 * D * D * D * D - D * D) / 12;
}

LL get_day(LL p, LL q) {
    for (LL d = 0; d < 100; d++) {
        if (q * sum(d) >= p * d) return d;
    }
    return 48763;
}

LL get_x(LL p, LL q) {
    LL D = get_day;
    x = p * d - sum(D) * q;
    return x;
}

LL get_y(LL x, LL p, LL q) {
    LL low = 0, high = 1e19, mid, ans = 0;
    auto ok = [&](LL y) {
        LL lhs = x - p * y + q * sum(y);
    };
    while (low <= high) {
        mid = (low + high) / 2;
        if (ok(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL q, p; cin >> q >> p;

    LL x = get_x(p, q);
    LL y = get_y(x, p, q);

    cout << x << " " << y << "\n";
}

