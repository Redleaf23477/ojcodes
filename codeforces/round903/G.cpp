#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int BET = 26;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n), bit(n + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    int query(int x) {
        int sum = 0;
        for (; x > 0; x -= lowbit(x)) {
            sum += bit[x];
        }
        return sum;
    }
    void modify(int x, int val) {
        for (; x <= n; x += lowbit(x)) {
            bit[x] += val;
        }
    }
    int get_range(int l, int r) {
        if (r < l) return 0;
        return query(r) - query(l - 1);
    }
};

// use BIT and 1-base index
void solve() {
    int n, q; cin >> n >> q;
    string str; cin >> str;
    BIT char_val(n);
    BIT two(n), three(n);
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && str[i] == str[i + 1]) {
            two.modify(i + 1, 1);
        }
        if (i + 2 < n && str[i] == str[i + 2]) {
            three.modify(i + 1, 1);
        }
    }

    auto is_equal_char = [&](int x, int y) {
        int a = ((str[x - 1] - 'a') + char_val.query(x)) % BET;
        int b = ((str[y - 1] - 'a') + char_val.query(y)) % BET;
        return a == b;
    };

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, val; cin >> l >> r >> val; val %= BET;
            vector<pair<int,int>> two_pos {{l - 1, l}, {r, r + 1}};
            vector<pair<int,int>> three_pos {{l - 2, l}, {l - 1, l + 1}, {r - 1, r + 1}, {r, r + 2}};
            // 0. check the endpoints
            for (auto [x, y] : two_pos) {
                if (1 <= x && x <= n && 1 <= y && y <= n && is_equal_char(x, y)) {
                    two.modify(x, -1);
                }
            }
            for (auto [x, y] : three_pos) {
                if (1 <= x && x <= n && 1 <= y && y <= n && is_equal_char(x, y)) {
                    three.modify(x, -1);
                }
            }
            // 1. range update
            char_val.modify(l, val);
            if (r + 1 <= n) char_val.modify(r + 1, -val);
            // 2. check the endpoints
            for (auto [x, y] : two_pos) {
                if (1 <= x && x <= n && 1 <= y && y <= n && is_equal_char(x, y)) {
                    two.modify(x, 1);
                }
            }
            for (auto [x, y] : three_pos) {
                if (1 <= x && x <= n && 1 <= y && y <= n && is_equal_char(x, y)) {
                    three.modify(x, 1);
                }
            }
        } else {
            int l, r; cin >> l >> r;
            if (two.get_range(l, r - 1) > 0 || three.get_range(l, r - 2) > 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }

        /*
        cerr << "char: ";
        for (int i = 1; i <= n; i++) {
            cerr << (char)('a' + (str[i - 1] - 'a' + char_val.query(i)) % BET) << " ";
        }
        cerr << endl;
        cerr << "two: ";
        for (int i = 1; i <= n; i++) {
            cerr << two.get_range(i, i) << " ";
        }
        cerr << endl;
        cerr << "three: ";
        for (int i = 1; i <= n; i++) {
            cerr << three.get_range(i, i) << " ";
        }
        cerr << endl;
        */
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

