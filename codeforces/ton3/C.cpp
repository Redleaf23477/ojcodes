#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int str_xor(string &A, string &B) {
    string C(A.size(), 0);
    for (size_t i = 0; i < A.size(); i++) {
        C[i] = '0' + ((A[i] - '0') ^ (B[i] - '0'));
    }
    for (size_t i = 1; i < C.size(); i++) {
        if (C[i] != C[i-1]) return -1;
    }
    return C[0] - '0';
}

void flip(string &S, int l, int r) {
    for (int i = l; i <= r; i++) {
        S[i] = (S[i] == '0'? '1' : '0');
    }
}

void solve() {
    int n; cin >> n;
    string A, B; cin >> A >> B;
    int res = str_xor(A, B);
    if (res == -1) {
        cout << "NO\n"; return;
    }

    vector<pair<int,int>> ans;

    // make them xor = 1
    if (res == 0) {
        ans.emplace_back(0, A.size()-1);
        flip(A, 0, A.size() - 1);
    }

    if (n > 2) {
        // make A[0], A[1] consecutive 1
        if (A[0] == '0' && A[1] == '0') {
            ans.emplace_back(0, 1);
            flip(A, 0, 1);
            flip(B, 2, n-1);
            ans.emplace_back(2, n-1);
            flip(A, 2, n-1);
            flip(B, 0, 1);
        } else if (A[0] == '0') {
            ans.emplace_back(0, 0);
            flip(A, 0, 0);
            flip(B, 1, n-1);
            ans.emplace_back(2, n-1);
            flip(A, 2, n-1);
            flip(B, 0, 1);
        } else if (A[1] == '0') {
            ans.emplace_back(1, 1);
            flip(A, 1, 1);
            flip(B, 0, 0), flip(B, 2, n-1);
            ans.emplace_back(2, n-1);
            flip(A, 2, n-1);
            flip(B, 0, 1);
        }

        // A: 11...
        // B: 00...
        // where A ^ B == 1

        // 1) count 1 in A
        int A_one_cnt = 0;
        for (auto ch : A) A_one_cnt += (ch == '1');
        if (A_one_cnt == n) {
            // all 1
            ans.emplace_back(0, n-1);
            flip(A, 0, n-1);
        } else if (A_one_cnt % 2 == 0) {
            // flip A[0], A[1] together
            ans.emplace_back(0, 1);
            flip(A, 0, 1);
            flip(B, 2, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (A[i] == '1') ans.emplace_back(i, i);
        }
    } else {
        if (A[0] == '0' && A[1] == '0') {
            ans.emplace_back(0, 0);
            ans.emplace_back(1, 1);
            ans.emplace_back(0, 1);
        } else if (A[0] == '0') {
            ans.emplace_back(1, 1);
        } else if (A[1] == '0') {
            ans.emplace_back(0, 0);
        } else {
            ans.emplace_back(0, 1);
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto [a, b] : ans) cout << a+1 << " " << b+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

