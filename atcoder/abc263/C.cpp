#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    vector<int> stk;
    function<void(int)> dfs = [&](int val) {
        if ((int)stk.size() == N) {
            for (auto x : stk) cout << x << " ";
            cout << "\n";
        } else {
            for (int v = val; v <= M; v++) {
                stk.emplace_back(v);
                dfs(v + 1);
            }
        }
        stk.pop_back();
    };
    dfs(1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



