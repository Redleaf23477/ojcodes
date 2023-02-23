#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<vector<int>> num_pos(n+1);
    for (int i = 0; i < n; i++) {
        num_pos[arr[i]].emplace_back(i);
        if (num_pos[arr[i]].size() >= 3) {
            cout << "NO\n"; return;
        }
    }
    vector<int> A(n, 0), B(n, 0);
    vector<int> A_buff, B_buff;
    // place the num from big to small
    for (int num = n; num > 0; num--) {
        auto &P = num_pos[num];
        if (P.size() == 2) {
            A[P[0]] = num;
            B[P[1]] = num;
            A_buff.emplace_back(P[1]);
            B_buff.emplace_back(P[0]);
        } else if (P.size() == 1) {
            A[P[0]] = num;
            B[P[0]] = num;
        } else {
            if (A_buff.empty() || B_buff.empty()) {
                cout << "NO\n"; return;
            }
            A[A_buff.back()] = num;
            B[B_buff.back()] = num;
            A_buff.pop_back();
            B_buff.pop_back();
        }
    }
    cout << "YES\n";
    for (auto x : A) cout << x << " ";
    cout << "\n";
    for (auto x : B) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

