#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string A; cin >> A;
    string B; cin >> B;
    
    // trivial case: A == B
    if (A == B) {
        cout << 0 << "\n"; 
        return;
    }
    // trivial case: A != B && (A == 0 or B == 0)
    if (A == string(n, '0') || B == string(n, '0')) {
        cout << -1 << "\n";
        return;
    }

    vector<int> ans;
    auto myxor = [](char a, char b) {
        a -= '0', b -= '0';
        a ^= b;
        return a + '0';
    };
    auto find_leftmost_bit = [&](string &S) {
        for (int i = 0; i < n; i++) {
            if (S[i] == '1') return i;
        }
        return 48763;
    };
    auto find_rightmost_bit = [&](string &S) {
        int rb = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] == '1') rb = i;
        }
        return rb;
    };
    auto do_A_leftshift = [&](int step) {
        ans.emplace_back(step);
        string tmp = A;
        for (int i = 0; i < n; i++) {
            A[i] = myxor(A[i], (i+step < n? tmp[i+step] : '0'));
        }
        // cerr << A << endl;
    };
    auto do_A_rightshift = [&](int step) {
        ans.emplace_back(-step);
        string tmp = A;
        for (int i = 0; i < n; i++) {
            A[i] = myxor(A[i], (i-step >= 0? tmp[i-step] : '0'));
        }
        // cerr << A << endl;
    };

    int B_rightmost = find_rightmost_bit(B);
    auto step0 = [&]() {
        if (A[B_rightmost] == '1') return;
        int A_leftmost = find_leftmost_bit(A);
        if (A_leftmost < B_rightmost) {
            do_A_rightshift(B_rightmost - A_leftmost);
        } else {
            do_A_leftshift(A_leftmost - B_rightmost);
        }
    };
    auto step1 = [&]() {
        int rb;
        for (rb = n-1; rb != B_rightmost; rb--) {
            if (A[rb] == '0') continue;
            int r = rb - 1;
            while (A[r] != '1') r--;
            do_A_rightshift(rb - r);
        }
    };

    auto step2 = [&]() {
        for (int i = B_rightmost - 1; i >= 0; i--) {
            if (A[i] != B[i]) {
                do_A_leftshift(B_rightmost - i);
            }
        }
    };

    // 0. mark B
    step0();
    // 1. reset smaller bits
    step1();
    // 2. deal with the remaining bits
    step2();

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

