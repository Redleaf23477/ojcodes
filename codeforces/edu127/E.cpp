#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    string tree; cin >> tree;
    vector<LL> ans((1<<n)-1, 1);
    function<string(int)> dfs = [&](int x) {
        if (x >= (int)ans.size()) return string();
        string lhs = dfs(2 * x + 1);
        string rhs = dfs(2 * x + 2);
        if (2 * x + 1 < (int)ans.size()) ans[x] = ans[2 * x + 1] * ans[2 * x + 2] % MOD;
        if (lhs != rhs) ans[x] = 2 * ans[x] % MOD;
        // cerr << "x = " << x << ", l = " << lhs << ", r = " << rhs << ", ans = " << ans[x] << endl;
        if (lhs < rhs) return tree[x] + lhs + rhs;
        else return tree[x] + rhs + lhs;
    };
    dfs(0);
    cout << ans[0] << "\n";
}

