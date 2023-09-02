#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<vector<int>> trim(vector<vector<int>> &A, int r, int c) {
    vector<vector<int>> ans;
    for (size_t i = 0; i < A.size(); i++) {
        if (((r >> i) & 1) == 0) continue;
        ans.emplace_back(vector<int>());
        for (size_t j = 0; j < A[0].size(); j++) {
            if ((c >> j) & 1) ans.back().emplace_back(A[i][j]);
        }
    }
    return ans;
}

void solve() {
    int Ra, Ca; cin >> Ra >> Ca;
    vector<vector<int>> A(Ra, vector<int>(Ca));
    for (auto &row : A) for (auto &col : row) cin >> col;
    int Rb, Cb; cin >> Rb >> Cb;
    vector<vector<int>> B(Rb, vector<int>(Cb));
    for (auto &row : B) for (auto &col : row) cin >> col;

    for (int r = 1; r < (1 << Ra); r++) {
        for (int c = 1; c < (1 << Ca); c++) {
            if (trim(A, r, c) == B) {
                cout << "Yes\n"; return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



