#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string A, B; cin >> A >> B;
    auto head = [&]() {
        if (A[0] == B[0]) {
            cout << "YES\n";
            cout << A[0] << '*' << "\n";
            return true;
        }
        return false;
    };
    auto tail = [&]() {
        if (A.back() == B.back()) {
            cout << "YES\n";
            cout << '*' << A.back() << "\n";
            return true;
        }
        return false;
    };
    auto mid = [&]() {
        for (size_t i = 0; i < A.size(); i++) {
            for (size_t j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    if (i + 1 < A.size() && j + 1 < B.size() && A[i+1] == B[j+1]) {
                        cout << "YES\n";
                        cout << '*' << A[i] << A[i+1] << '*' << "\n";
                        return true;
                    }
                }
            }
        }
        return false;
    };

    if (head()) return;
    if (tail()) return;
    if (mid()) return;
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

