#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void find_pa(vector<int> &arr, vector<int> &pa) {
    int n = arr.size();
    set<int> vis;
    pa[0] = 0, vis.insert(arr[0]);
    for (int i = 1; i < n; i++) {
        if (vis.count(arr[i]) > 0) {
            pa[i] = pa[i-1];
        } else {
            pa[i] = i, vis.insert(arr[i]);
        }
    }
}

void find_eq(vector<int> &A, vector<int> &B, vector<int> &eq) {
    int n = A.size();
    eq.assign(n, -1);

    set<int> vis;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && vis.count(A[i]) == 0) {
            vis.insert(B[j]), j++;
        }
        if (vis.count(A[i]) == 0) break;
        else eq[i] = j - 1;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    vector<int> pa_A(n, 0), pa_B(n, 0);
    find_pa(A, pa_A);
    find_pa(B, pa_B);

    vector<int> eq_A, eq_B;
    find_eq(A, B, eq_A);
    find_eq(B, A, eq_B);

    int Q; cin >> Q;
    while (Q--) {
        int x, y; cin >> x >> y; x--, y--;
        int pa_x = pa_A[x], pa_y = pa_B[y];
        if (eq_A[pa_x] == pa_y && eq_B[pa_y] == pa_x) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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



