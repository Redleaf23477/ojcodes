#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL solve(LL N, int max_len) {
    vector<LL> dec(max_len + 1, 1);  // 10^i
    for (int i = 1; i <= max_len; i++) {
        dec[i] = 10 * dec[i-1];
    }
    vector<vector<LL>> cnt(max_len + 1, vector<LL>(4, 0));  // cnt[len][1-3]
    for (int len = max_len; len >= 0; len--) {
        for (LL digit : {3, 2, 1}) {
            LL q = N / digit / dec[len];
            cnt[len][digit] = q;
            N -= digit * dec[len] * q;
        }
    }
    /*
    cerr << "DEBUG cnt:" << endl;
    cerr << "max_len = " << max_len << endl;
    for (int d = 1; d <= 3; d++) {
        for (int len = 0; len <= max_len; len++) {
            cerr << cnt[len][d] << " ";
        }
        cerr << endl;
    }
    */
    vector<LL> digit_cnt(max_len + 1, 0);
    function<void(int,int)> borrow = [&](int len, int digit) {
        if (digit == 3) {
            if (cnt[len + 1][1] == 0) borrow(len + 1, 1);
            cnt[len + 1][1] -= 1, cnt[len][3] += 3, cnt[len][1] += 1;
            digit_cnt[len + 1] -= 1, digit_cnt[len] += 4;
        } else if (digit == 2) {
            if (cnt[len][3] == 0) borrow(len, digit + 1);
            cnt[len][3] -= 1, cnt[len][2] += 1, cnt[len][1] += 1; 
            digit_cnt[len] += 1;
        } else {  // digit == 1
            if (cnt[len][2] == 0) borrow(len, digit + 1);
            cnt[len][2] -= 1, cnt[len][1] += 2; 
            digit_cnt[len] += 1;
        }
    };
    for (int len = 0; len <= max_len; len++) {
        digit_cnt[len] = cnt[len][0] + cnt[len][1] + cnt[len][2];
    }
    for (int len = 0; len < max_len; len++) {
        while (digit_cnt[len] < *max_element(digit_cnt.begin() + len + 1, digit_cnt.end())) {
            borrow(len, 1);
        }
    }
    return cnt[0][1] + cnt[0][2] + cnt[0][3];
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL N; cin >> N;
        LL ans = N;
        for (int max_len = 5; max_len > 0; max_len--) {
            LL res = solve(N, max_len);
            if (res != -1) ans = min(ans, res);
        }
        cout << ans << "\n";
    }
}

