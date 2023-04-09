#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    vector<pair<int,int>> stk;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (stk.empty()) {
            stk.emplace_back(x, 1);
            ans++;
        } else if (stk.back().first != x) {
            stk.emplace_back(x, 1);
            ans++;
        } else {
            stk.back().second += 1;
            ans++;
            if (stk.back().second == x) {
                stk.pop_back();
                ans -= x;
            }
        }
        cout << ans << "\n";
    }
}

