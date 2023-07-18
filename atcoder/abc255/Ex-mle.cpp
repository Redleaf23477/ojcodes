#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

const LL inv2 = fastpw(2, MOD - 2);
LL arith_sum(LL l, LL r) {
    return ((l + r) % MOD) * ((r - l + 1) % MOD) % MOD * inv2 % MOD;
}

struct Seg1D {
    struct Node {
        int st, t_add;
        bool t_rst;
        unique_ptr<Node> lchild, rchild;
        Node(): st(0), t_add(0), t_rst(false), lchild(nullptr), rchild(nullptr) {
        }
        void update_reset_tag() {
            t_rst = true;
            t_add = 0;
            st = 0;
        }
        void update_add_tag(LL l, LL r, LL val) {
            val %= MOD;
            t_add = (t_add + val) % MOD;
            st = (st + val * arith_sum(l, r) % MOD) % MOD;
        }
        void down(LL l, LL r) {
            LL mid = (l + r) / 2;
            if (t_rst == true) {
                if (lchild) lchild->update_reset_tag();
                if (rchild) rchild->update_reset_tag();
                t_rst = false;
            }
            if (t_add != 0) {
                if (!lchild) lchild = make_unique<Node>();
                if (!rchild) rchild = make_unique<Node>();
                lchild->update_add_tag(l, mid, t_add);
                rchild->update_add_tag(mid + 1, r, t_add);
                t_add = 0;
            }
        }
        void add(LL l, LL r, LL val) {
            update_add_tag(l, r, val); 
        }
        LL sum(LL l, LL r, LL L, LL R) {
            if (L <= l && r <= R) return st;
            if (r < L || R < l) return 0;
            LL mid = (l + r) / 2;
            down(l, r);
            LL ans = 0;
            if (lchild) ans += lchild->sum(l, mid, L, R);
            if (rchild) ans += rchild->sum(mid + 1, r, L, R);
            return ans % MOD;
        }
        void reset(LL l, LL r, LL L, LL R) {
            if (L <= l && r <= R) {
                update_reset_tag();
                return;
            }
            if (r < L || R < l) return;
            LL mid = (l + r) / 2;
            down(l, r);
            st = 0;
            if (lchild) {
                lchild->reset(l, mid, L, R);
                st = (st + lchild->st) % MOD;
            }
            if (rchild) {
                rchild->reset(mid + 1, r, L, R);
                st = (st + rchild->st) % MOD;
            }
        }
    };
    using NodePtr = unique_ptr<Node>;

    LL n;
    NodePtr root;

    Seg1D(LL _n) : n(_n), root(make_unique<Node>()) {}

    // st[i] += val * i for all i
    void add(LL val) { return root->add(1, n, val); }

    // return st[L : R] % MOD
    LL sum(LL L, LL R) { return root->sum(1, n, L, R); }

    // st[i] = 0 for i in [l, r]
    void reset(LL L, LL R) { return root->reset(1, n, L, R); }
};

void solve() {
    LL N, Q; cin >> N >> Q;
    LL prev_day = 0;
    Seg1D st(N + 1);
    while (Q--) {
        LL day; cin >> day;
        LL l, r; cin >> l >> r;

        st.add(day - prev_day);
        cout << st.sum(l, r) << "\n";
        st.reset(l, r);

        prev_day = day;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



