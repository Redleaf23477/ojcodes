#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

inline int lowbit(int x) { return x & -x; }

struct BIT1D {
    int n;
    vector<int> bit;
    BIT1D(int _n) : n(_n), bit(n+1, 0) {}
    void modify(int x, int val) {
        for (; x <= n; x += lowbit(x)) bit[x] += val;
    }
    int query(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
};

struct BIT2D {
    int n, m;
    vector<BIT1D> bit;
    BIT2D(int _n, int _m) : n(_n), m(_m), bit(n+1, BIT1D(m)) {}
    void modify(int x, int y, int val) {
        for (; x <= n; x += lowbit(x)) bit[x].modify(y, val);
    }
    int query(int x, int y) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) ans += bit[x].query(y);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    BIT2D bit(n, n);
    vector<vector<char>> maze(n+1, vector<char>(n+1, '.'));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> maze[i][j];
        if (maze[i][j] == '*') bit.modify(i, j, 1);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int r, c; cin >> r >> c;
            if (maze[r][c] == '.') {
                bit.modify(r, c, 1);
                maze[r][c] = '*';
            } else {
                bit.modify(r, c, -1);
                maze[r][c] = '.';
            }
        } else if (op == 2) {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            cout << bit.query(r2, c2) - bit.query(r2, c1-1) - bit.query(r1-1, c2) + bit.query(r1-1, c1-1) << "\n";
        }
    }
}
