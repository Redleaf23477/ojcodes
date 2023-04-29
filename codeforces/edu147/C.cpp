#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    auto try_try_see = [](int num) {
        int ans = 0;
        while (num > 0) {
            int bye = (num + 1) / 2;
            ans++;
            num -= bye;
        }
        return ans;
    };
    auto run = [&](char left) {
        int ans = 0, cnt = 0;
        for (auto ch : str) {
            if (ch == left) {
                ans = max(ans, try_try_see(cnt));
                cnt = 0;
            } else {
                cnt++;
            }
        }
        ans = max(ans, try_try_see(cnt));
        return ans;
    };
    int ans = str.size();
    for (char ch = 'a'; ch <= 'z'; ch++) {
        ans = min(ans, run(ch));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



