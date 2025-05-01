#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// brute forces
struct E1 {
    int l, n, m;
    vector<int> arr;
    vector<vector<int>> mat;

    E1() {
        cin >> l >> n >> m;
        arr.assign(l, 0);
        for (auto &x : arr) cin >> x;
        mat.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> mem;
    void run() {
        mem.assign(l, vector<int>(n * m, -1));
        cout << "NT"[dfs(0, 0)] << "\n";
    }
    int dfs(int arr_idx, int mat_idx) {
        // `turn` loses
        if (arr_idx == l || mat_idx >= n * m) {
            return 0;
        }

        // check previous results
        if (mem[arr_idx][mat_idx] != -1) {
            return mem[arr_idx][mat_idx];
        }

        // do dfs
        int r = mat_idx / m;
        int c = mat_idx % m;
        
        int res = 0;
        for (int qr = r; qr < n; qr++) {
            for (int qc = c; qc < m; qc++) {
                if (mat[qr][qc] == arr[arr_idx]) {
                    int next_mat_idx = (qr + 1) * m + (qc + 1);
                    int subres = dfs(arr_idx + 1, next_mat_idx);
                    if (subres == 0) {
                        // haha I win
                        res = 1; break;
                    }
                }
                if (res == 1) break;
            }
        }

        return mem[arr_idx][mat_idx] = res;
    }
};

void solve() {
    E1().run();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}
