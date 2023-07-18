#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    int head = 0;
    while (Q--) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            head = (head - x + N) % N;
        } else {
            cout << S[(head + x - 1) % N] << "\n";
        }
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



