#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

string rot(string s) {
    string ans = s;
    for (size_t i = 0; i < s.size(); i++) {
        s.push_back(s.front());
        s.erase(0, 1);
        ans = max(ans, s);
    }
    reverse(s.begin(), s.end());
    for (size_t i = 0; i < s.size(); i++) {
        s.push_back(s.front());
        s.erase(0, 1);
        ans = max(ans, s);
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    vector<string> A(N);
    for (auto &s : A) cin >> s;
    string ans = A[0];
    // row
    for (int i = 0; i < N; i++) {
        ans = max(ans, rot(A[i]));
    }
    // col
    for (int j = 0; j < N; j++) {
        string col(N, '0');
        for (int i = 0; i < N; i++) {
            col[i] = A[i][j];
        }
        ans = max(ans, rot(col));
    }
    // main diag
    string diag(N, '0');
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            diag[j] = A[(i + j) % N][j];
        }
        ans = max(ans, rot(diag));
        for (int j = 0; j < N; j++) {
            diag[j] = A[(i + j) % N][N - 1 - j];
        }
        ans = max(ans, rot(diag));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



