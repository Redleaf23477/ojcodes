#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 0);
    sort(arr.begin(), arr.end(), [&](int lhs, int rhs) {
        if (A[lhs] != A[rhs]) return A[lhs] > A[rhs];
        else return lhs < rhs;
    });
    sort(arr.begin() + X, arr.end(), [&](int lhs, int rhs) {
        if (B[lhs] != B[rhs]) return B[lhs] > B[rhs];
        else return lhs < rhs;
    });
    sort(arr.begin() + X + Y, arr.end(), [&](int lhs, int rhs) {
        if (A[lhs] + B[lhs] != A[rhs] + B[rhs]) return A[lhs] + B[lhs] > A[rhs] + B[rhs];
        else return lhs < rhs;
    });
    sort(arr.begin(), arr.begin() + X + Y + Z);
    for (int i = 0; i < X + Y + Z; i++) {
        cout << arr[i] + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



