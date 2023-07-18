#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        a += (A[i] == B[i]);
    }
    map<int,int> cnt_A, cnt_B;
    for (int i = 0; i < n; i++) {
        cnt_A[A[i]]++;
        cnt_B[B[i]]++;
    }
    for (auto [val, cnt] : cnt_A) {
        if (cnt_B.count(val) != 0) {
            b += min(cnt, cnt_B[val]);
        }
    }
    cout << a << "\n" << b - a << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



