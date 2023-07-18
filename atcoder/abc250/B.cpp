#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, A, B; cin >> N >> A >> B;
    vector<char> ch {'.', '#'};
    for (int i = 0; i < N; i++) for (int a = 0; a < A; a++) {
        for (int j = 0; j < N; j++) for (int b = 0; b < B; b++) {
            cout << ch[(i + j) % 2];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



