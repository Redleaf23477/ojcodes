#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    LL T; cin >> T;
    vector<LL> A(N - 1);
    for (auto &x : A) cin >> x;
    vector<LL> bonus(N - 1, 0);
    for (int i = 0; i < M; i++) {
        int X; cin >> X; X--;
        LL Y; cin >> Y;
        bonus[X] += Y;
    }

    for (int i = 0; i < N - 1; i++) {
        T += bonus[i];
        T -= A[i];
        if (T <= 0) {
            cout << "No\n"; return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



