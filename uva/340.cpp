#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, caseN = 0;
    while (cin >> n && n) {
        cout << "Game " << ++caseN << ":" << endl;
        vector<int> ans(n);
        vector<int> ans_cnt(1001, 0); 
        for (auto &x : ans) {
            cin >> x;
            ans_cnt[x] += 1;
        }
        while (true) {
            vector<int> guess(n);
            vector<int> guess_cnt(1001, 0);
            for (auto &x : guess) {
                cin >> x;
                guess_cnt[x] += 1;
            }
            if (guess_cnt[0] == n) break;
            int a = 0, b = 0;
            for (int i = 1; i <= 1000; i++) {
                b += min(ans_cnt[i], guess_cnt[i]);
            }
            for (int i = 0; i < n; i++) {
                a += (ans[i] == guess[i]);
            }
            b -= a;
            cout << "    (" << a << "," << b << ")" << endl;
        }
    }
}