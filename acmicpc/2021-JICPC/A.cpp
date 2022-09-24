#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool ok() {
    int n; cin >> n;
    vector<string> A(n), B(n);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    auto get_tone = [](string &str) {
        return str.back() == '1' || str.back() == '2';
    };

    for (int i = 0; i < n; i++) {
        if (get_tone(A[i]) == get_tone(B[i])) return false;
    }
    if (get_tone(A.back())) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        if (ok()) cout << "YES\n";
        else cout << "NO\n";
    }
}

