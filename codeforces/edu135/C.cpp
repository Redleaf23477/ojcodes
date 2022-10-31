#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int f(int x) {
    int ans = 0;
    for (; x > 0; x /= 10) ans++;
    return ans;
}

void solve() {
    int n; cin >> n;
    multiset<int> A, B;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        B.insert(x);
    }
    int ans = 0;
    auto run = [&ans](multiset<int> &A, multiset<int> &B) {
        auto at = A.end(); at--;
        auto it = B.find(*at);
        if (it != B.end()) {
            A.erase(at), B.erase(it);
        } else {
            int x = f(*at);
            A.erase(at);
            A.insert(x);
            ans++;
        }
    };
    while (!A.empty()) {
        if (*A.rbegin() > *B.rbegin()) {
            run(A, B);
        } else {
            run(B, A);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

