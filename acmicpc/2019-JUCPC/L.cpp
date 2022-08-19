#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str; cin >> str;
    int n = str.size();

    bool ok = true;

    int keep_c = 0, a_cnt = 0, c_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'a') a_cnt++;
        else if (str[i] == 'b') a_cnt--;
        else if (str[i] == 'c') a_cnt--, c_cnt++;
    }
    if (a_cnt < 0) {
        if (c_cnt + a_cnt >= 0) {
            keep_c = -a_cnt;
        } else {
            ok = false;
        }
    }

    stack<char> stk;
    vector<tuple<int,int>> ans;
    for (int i = 0; i < n && ok; i++) {
        char ch = str[i];
        if (ch == 'a') stk.emplace(ch);
        else if (ch == 'b') {
            // do b
            if (stk.empty()) ok = false;
            else {
                // b -> bc
                ans.emplace_back(2, stk.size() + 1);
                // abc -> x
                ans.emplace_back(4, stk.size());
                // clean up
                stk.pop();
            }
        } else {
            // do c
            if (stk.empty()) ok = false;
            else {
                if (keep_c > 0) {
                    // c -> ba
                    ans.emplace_back(3, stk.size() + 1);
                    // b-> bc
                    ans.emplace_back(2, stk.size() + 1);
                    // abc -> x
                    ans.emplace_back(4, stk.size());
                    // clean up
                    keep_c--;
                } else {
                    // a -> ab
                    ans.emplace_back(1, stk.size());
                    // abc -> x
                    ans.emplace_back(4, stk.size());
                    // clean up
                    stk.pop();
                }
            }
        }
    }
    while (ok && !stk.empty()) {
        // do a
        // a -> ab
        ans.emplace_back(1, stk.size());
        // b -> bc
        ans.emplace_back(2, stk.size() + 1);
        // abc -> x
        ans.emplace_back(4, stk.size());
        // clean up
        stk.pop();
    }

    //    cerr << "ok = " << ok << ", size = " << ans.size() << endl;

    if (ok && ans.size() <= 3 * n) {
        cout << ans.size() << "\n";
        for (auto &[a, b] : ans) cout << a << " " << b << "\n";
    } else {
        cout << -1 << "\n";
    }
}

