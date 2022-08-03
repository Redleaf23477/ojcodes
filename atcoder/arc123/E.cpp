#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL N, Ax, Ay, Bx, By;
    cin >> N >> Ax >> Bx >> Ay >> By;
    if (Bx < By) swap(Ax, Bx), swap(Ay, By);

    // A = (Ax - Ay) = floor(n / By) - floor(n / Bx)
    LL lb = [&](LL A, LL low, LL high) {
        LL ans = -1;
        while (low <= high) {
            LL mid = (low + high) / 2;
            if (A == mid / By - mid / Bx) ans = mid, high = mid - 1;
            else if (A < mid / By - mid / Bx) high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }(Ax - Ay, 1, N);

    LL ub = [&](LL A, LL low, LL high) {
        LL ans = -1;
        while (low <= high) {
            LL mid = (low + high) / 2;
            if (A == mid / By - mid / Bx) ans = mid, low = mid + 1;
            else if (A < mid / By - mid / Bx) high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }(Ax - Ay, 1, N);

    cerr << "lb = " << lb << ", ub = " << ub << endl;

    if (lb == -1 || ub == -1) cout << 0 << "\n";
    else cout << ub - lb + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

