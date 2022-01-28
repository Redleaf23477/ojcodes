#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

using IT = vector<LL>::iterator;
const LL INF = 1e18;

LL f(IT L, IT R) {
    if (L+1 == R) {
        return *L;
    }
    IT mid = L + (R - L)/2;
    LL ans = max(f(L, mid), f(mid, R));
    LL lmax = -INF, rmax = -INF;
    LL sum = 0;
    for (auto it = mid-1; it >= L; it--) {
        sum += *it;
        lmax = max(lmax, sum);
    }
    sum = 0;
    for (auto it = mid; it != R; it++) {
        sum += *it;
        rmax = max(rmax, sum);
    }
    return max(ans, lmax + rmax);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    cout << f(arr.begin(), arr.end()) << endl;
}
