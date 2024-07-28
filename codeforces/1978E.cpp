#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n; n++;
    string A, B; cin >> A >> B;
    A = '1' + A;
    B = '0' + B;

    // consider str[0:i], #1s in A
    vector<int> acc(n, 0);
    acc[0] = 1;
    for (int i = 1; i < n; i++) {
        acc[i] = acc[i - 1] + (A[i] == '1');
    }
    
    // consider str[0:i], new #1s in A by op2
    vector<int> acc_op2(n, 0);
    for (int i = 2; i < n; i++) {
        acc_op2[i] = acc_op2[i - 1];
        if (B[i] == '1' and B[i - 2] == '1' and A[i - 1] != '1') {
            acc_op2[i] += 1;
        }
    }

    // consider str[0:i], new #1s in A by op1 then op2 with existing 1 in B
    vector<int> acc_op1(n, 0);
    vector<bool> B_can_1(n, false);
    for (int i = 2; i < n; i++) {
        acc_op1[i] = acc_op1[i - 1];
        if (A[i] == '0' and A[i - 2] == '0' and B[i - 1] != '1') {
            B_can_1[i - 1] = true;
            if (i - 3 >= 0 and B[i - 3] == '1' and A[i - 2] != '1') {
                acc_op1[i] += 1;
            }
        }
    }

    // consider str[0:i], new #1s in A by op2 with new 1 in B
    vector<int> acc_op2_step2(n, 0);
    for (int i = 2; i < n; i++) {
        acc_op2_step2[i] = acc_op2_step2[i - 1];
        if (B[i] == '1' and B_can_1[i - 2] and A[i - 1] != '1') {
            acc_op2_step2[i] += 1;
        }
    }

    // consider str[0:i], new #1s in A by op1 then op2 with new 1 in B
    vector<int> acc_op1_step2(n, 0);
    for (int i = 3; i < n; i++) {
        acc_op1_step2[i] = acc_op1_step2[i - 1];
        if (A[i] == '0' and A[i - 2] == '0' and B[i - 1] != '1') {
            // B_can_1[i - 1] = true;
            if (B_can_1[i - 3] and A[i - 2] != '1') {
                acc_op1_step2[i] += 1;
            }
        }
    }

    /*
    cerr << A << endl;
    cerr << B << endl;
    for (auto &arr : {acc, acc_op2, acc_op1, acc_op1_step2}) {
        for (auto x : arr) cerr << x;
        cerr << endl;
    }
    */

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int ans = acc[r] - acc[l - 1];
        // op2
        if (l + 1 <= r) {
            ans += acc_op2[r] - acc_op2[l + 1];
        }
        // op1
        if (l + 2 <= r) {
            ans += acc_op1[r] - acc_op1[l + 2];
        }
        // op2_step2
        if (l + 2 <= r) {
            ans += acc_op2_step2[r] - acc_op2_step2[l + 2];
        }
        // op1_step2
        if (l + 3 <= r) {
            ans += acc_op1_step2[r] - acc_op1_step2[l + 3];
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

