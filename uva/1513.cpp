#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int _n) : n(_n+1), bit(n, 0) {}
    int lowbit(int x) { return x & -x; }
    void modify(int pos, int val) {
        for (; pos < n; pos += lowbit(pos)) {
            bit[pos] += val;
        }
    }
    int query(int pos) {
        int ans = 0;
        for (; pos > 0; pos -= lowbit(pos)) {
            ans += bit[pos];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> pos(n+1, 0);
        BIT bit(n+m);
        for (int i = 1; i <= n; i++) bit.modify(i, 1);
        for (int i = 1; i <= n; i++) pos[i] = n-i+1;

        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            int p = pos[x];

            cout << n - bit.query(p) << " \n"[j==m-1];

            bit.modify(p, -1);
            pos[x] = n + j + 1;
            bit.modify(pos[x], 1);
        }
    }
}

