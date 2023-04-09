#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(string &A, string &B) {
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] == A[i-1]) return false;
    }
    for (size_t i = 1; i < B.size(); i++) {
        if (B[i] == B[i-1]) return false;
    }
    return true;
}

bool test(string A, string B) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i-1]) {
            while (A.size() > i) {
                B.push_back(A.back());
                A.pop_back();
            }
            if (good(A, B)) {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    string A, B; cin >> A >> B;
    if (test(A, B) == false) {
        cout << "No\n";
    } else if (test(B, A) == false) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



