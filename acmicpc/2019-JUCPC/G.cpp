#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> init_a(n), init_b(n);
    for (int i = 0; i < n; i++) {
        cin >> init_a[i] >> init_b[i];
    }
    for (LL i = 0, pre = 0; i < n; i++) {
        pre += init_a[i];
        init_b[i] -= pre[i];  // init_b = tolerance to die
    }


    BIT alive(n);
    Seg1D_A a_tree(n, init_a);  // prefix sum, binary search
    Seg1D_B b_tree(n, init_b);  // range min, range add

    auto robot = [&](LL x) {
        int new_die = 0, no_food = 0;

        // 1) binary search return point -> prefix sum of a
        auto [last_idx, prefix_sum] = a_tree.search(x);
        no_food = alive.query(n) - alive.query(last_idx + 1);

        // 2) while min check -> min of b - prefix a
        while (true) {
            auto [idx, tolerance] = a_tree.query(0, last_idx);
            if (idx == -1) break; // all die
            if (x - prefix_sum < tolerance) break;  // no new die

            new_die += 1;
            alive.modify(idx, -1);
            a_tree.modify(idx, n-1, -init_a[idx]);
            b_tree.modify(idx, n-1, -init_a[idx]);
        }


        cout << new_die << " " << no_food << "\n";
    };

    auto assign = [&](LL a, LL b, LL idx) {
    };

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            LL x; cin >> x;
            robot(x);
        } else if (op == 2) {
            LL a, b, idx; cin >> a >> b >> idx;
            assign(a, b, idx - 1);
        }
    }
}

