#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(K); 
    for (auto &x : A) cin >> x;
    A.emplace_back(N + 1);
    vector<int> L(Q);
    for (auto &x : L) cin >> x;

    for (auto x : L) {
        x--;
        if (A[x] + 1 < A[x + 1]) {
            A[x]++;
        }
    }

    for (int i = 0; i < K; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



