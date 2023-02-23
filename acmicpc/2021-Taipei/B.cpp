#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int check(string &A, string &B) {
    int cnt = 0;
    for (size_t i = 0; i < A.size(); i++) {
        cnt += (A[i] == B[i]);
    }
    return cnt;
}

void solve() {
    int n; cin >> n;
    string A, B; cin >> A >> B;
    cout << check(A, B) << " ";
    int ans = 0, l = 1, r = 1;
    // odd
    for (int mid = 0; mid < n; mid++) {
        for (int len = 0; len <= n; len++) {
            if (mid - len >= 0 && mid + len < n) {
                swap(B[mid - len], B[mid + len]);
                int c = check(A, B);
                if (c > ans) ans = c, l = mid - len + 1, r = mid + len + 1;
                else if (c == ans && r - l > 2 * len) ans = c, l = mid - len + 1, r = mid + len + 1;
            } else {
                break;
            }
        }
        // recover
        for (int len = 0; len <= n; len++) {
            if (mid - len >= 0 && mid + len < n) {
                swap(B[mid - len], B[mid + len]);
            } else {
                break;
            }
        }
    }
    // even
    for (int mid = 0; mid < n; mid++) {
        for (int len = 1; len <= n; len++) {
            if (mid - len + 1 >= 0 && mid + len < n) {
                swap(B[mid - len + 1], B[mid + len]);
                int c = check(A, B);
                if (c > ans) ans = c, l = mid - len + 2, r = mid + len + 1;
                else if (c == ans && r - l > 2 * len - 1) l = mid - len + 2, r = mid + len + 1;
            } else {
                break;
            }
        }
        // recover
        for (int len = 1; len <= n; len++) {
            if (mid - len + 1 >= 0 && mid + len < n) {
                swap(B[mid - len + 1], B[mid + len]);
            }
        }
    }
    cout << ans << " " << l << " " << r << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

