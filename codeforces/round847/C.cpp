#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int get_missing(vector<int> &A, int n) {
    vector<bool> vis(n+1, false);
    for (auto x : A) vis[x] = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return i;
    }
    return -1;
}

bool is_subseq(vector<int> &small, vector<int> &large) {
    bool skip = false;
    for (size_t i = 0, j = 0; j < large.size(); j++) {
        if (i < small.size() && small[i] == large[j]) {
            i++;
        } else if (skip == false) {
            skip = true;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> A(n-1), B(n-1), C(n-1);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    for (int i = 2; i < n; i++) {
        for (auto &x : C) cin >> x;
    }

    int missing_A = get_missing(A, n);
    for (int i = 0; i < n; i++) {
        vector<int> A2 = A;
        A2.insert(A2.begin() + i, missing_A);
        if (is_subseq(B, A2) && is_subseq(C, A2)) {
            for (auto x : A2) cout << x << " ";
            cout << "\n";
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



