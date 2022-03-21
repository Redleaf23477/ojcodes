#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct BIT {
    int n;
    vector<LL> bit;

    BIT(int _n) : n(_n), bit(_n+1, 0) {}

    int lowbit(int x) { return x & (-x); }
    void modify(int x, int v) {
        for (; x <= n; x += lowbit(x)) {
            bit[x] += v;
        }
    }
    LL query(int x) {
        LL ans = 0;
        for (; x > 0; x -= lowbit(x)) {
            ans += bit[x];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<int> arr(n+1);
    BIT bit(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        bit.modify(i, arr[i]);
    }
    while (q--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            bit.modify(a, -arr[a]);
            bit.modify(a, b);
            arr[a] = b;
        } else {
            cout << bit.query(b) - bit.query(a-1) << "\n";
        }
    }
}

