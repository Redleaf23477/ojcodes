#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// I am not sure if using lg with GG
constexpr double lg3 = log2(3.0);
constexpr LL MOD = 1e9+7;

bool bigger(vector<int> test, vector<int> ans) {
    if (test[0] > 0) return false;
    else if (ans[0] > 0) return true;

    int more_2 = test[2] - ans[2];
    int more_3 = test[3] - ans[3];
    if (more_2 > 0 && more_3 > 0) {
        return true;
    } else if (more_2 <= 0 && more_3 <= 0) {
        return false;
    } else if (more_2 > 0) {
        return more_2 > lg3 * (-more_3);
    } else {
        return lg3 * more_3 > (-more_2);
    }
}

LL calc(vector<int> ans) {
    LL prod = 1;
    if (ans[0] > 0) prod = 0;
    for (int num = 2; num <= 3; num++) {
        for (int cnt = 0; cnt < ans[num]; cnt++) {
            prod = prod * num % MOD;
        }
    }
    return prod;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char ch; cin >> ch;
            arr[r][c] = ch - '0';
        }
    }

    vector<vector<int>> row(n, vector<int>(4, 0));
    vector<vector<int>> col(n, vector<int>(4, 0));
    vector<vector<int>> diag(3 * n, vector<int>(4, 0)); // dir: /
    vector<vector<int>> diag2(3 * n, vector<int>(4, 0)); // dir: backslash
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            row[r][arr[r][c]]++;
            col[c][arr[r][c]]++;
            diag[r + c][arr[r][c]]++;
            diag2[r - c + n][arr[r][c]]++;
        }
    }

    vector<int> ans(4, 0);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            vector<int> cross(4, 0), X(4, 0);
            for (int i = 0; i < 4; i++) {
                cross[i] = row[r][i] + col[c][i];
                X[i] = diag[r + c][i] + diag2[r - c + n][i];
            }
            cross[arr[r][c]]--;
            X[arr[r][c]]--;

            if (bigger(cross, ans)) {
                ans = cross;
                cerr << "ans is cross " << r << " " << c << endl;
                cerr << "cross " << r << " " << c << " = " << cross[0] << " " << cross[1] << " " << cross[2] << " " << cross[3] << endl;
            }
            if (bigger(X, ans)) {
                ans = X;
                cerr << "ans is X " << r << " " << c << endl;
                cerr << "X " << r << " " << c << " = " << X[0] << " " << X[1] << " " << X[2] << " " << X[3] << endl;
            }
        }
    } 
    cout << calc(ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



