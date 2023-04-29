#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL N = 5e6;
constexpr LL LGN = log2(N) + 1;

vector<LL> phi(N+1);
void build_phi_table() {
    iota(phi.begin(), phi.end(), 0);
    for (LL i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (LL j = i; j <= N; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    /*
    for (int i = 1; i <= 20; i++) {
        cerr << "phi(" << i << ") = " << phi[i] << endl;
    }
    */
}

vector<LL> dep(N+1, 0);
void build_phi_tree_dep() {
    for (int i = 2; i <= N; i++) {
        dep[i] = 1 + dep[phi[i]];
    }
}

vector<vector<int>> jmp(LGN+1, vector<int>(N+1, -1));
void build_doubling() {
    for (int i = 1; i <= N; i++) {
        jmp[0][i] = phi[i];
    }
    for (int lg = 1; lg <= LGN; lg++) {
        for (int i = 1; i <= N; i++) {
            jmp[lg][i] = jmp[lg-1][jmp[lg-1][i]];
        }
    }
    /*
    for (int i = 1; i <= 20; i++) {
        cerr << i << ": ";
        for (int j = 0; j < 4; j++) {
            cerr << jmp[j][i] << " ";
        }
        cerr << endl;
    }
    */
}
int jump_lca(int node, int step) {
    for (int i = 0; i <= LGN; i++) {
        if ((step >> i) & 1) {
            node = jmp[i][node];
        }
    }
    return node;
}
int find_lca(int a, int b) {
    // special case: let -1 denotes a dummy node
    if (a == -1) return b;
    if (b == -1) return a;

    if (dep[a] > dep[b]) swap(a, b);
    jump_lca(b, dep[b] - dep[a]);
    for (int i = LGN; i >= 0; i--) {
        if (jmp[i][a] != jmp[i][b]) {
            a = jmp[i][a];
            b = jmp[i][b];
        }
    }
    return jmp[0][a];
}

struct Seg1D {
    struct Node {
        int lca, dist;
        LL dep_sum;
        Node(int _lca = -1, int _dist = 0, LL _dep = 0) 
            : lca(_lca), dist(_dist), dep_sum(_dep) {}
    };
    int n;
    vector<int> const &arr;
    vector<Node> st;
    vector<int> tag;
    Seg1D(int _n, vector<int> const &_arr) : n(_n), arr(_arr), st(4*n), tag(4*n, 0) {
        build(0, n-1, 1);
    }
    void up(int idx, int lson, int rson) {
        st[idx].lca = find_lca(st[lson].lca, st[rson].lca);
        st[idx].dist = min(dep[st[idx].lca] - dep[st[lson].lca] + st[lson].dist, 
                dep[st[idx].lca] - dep[st[rson].lca] + st[rson].dist);
        st[idx].dep_sum = st[lson].dep_sum + st[rson].dep_sum;
    }
    void update_node(int idx, int tag_val, LL seg_len) {
        if (tag_val > st[idx].dist) {
            int step = tag_val - st[idx].dist;
            st[idx].lca = jump_lca(st[idx].lca, step);
            st[idx].dist = 0;
        } else {
            st[idx].dist -= tag_val;
        }
    }
    void down(int idx, int lson, int rson) {
        if (tag[idx] != 0) {
            tag[lson] += tag[idx];
            tag[rson] += tag[idx];
            update_node(lson, tag[idx]);
            update_node(rson, tag[idx]);
        }
        tag[idx] = 0;
    }
    void build(int l, int r, int idx) {
        if (l == r) {
            st[idx] = Node(arr[l], 0, dep[arr[l]]);
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        up(idx, lson, rson);
    }
    void modify(int L, int R) { modify(0, n-1, 1, L, R); }
    void modify(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            tag[idx] += 1;
            update_node(idx, 1);
            return;
        }
        if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson);
        modify(l, mid, lson, L, R);
        modify(mid+1, r, rson, L, R);
        up(idx, lson, rson);
    }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }
    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return st[idx].lca;
        }
        if (r < L || R < l) {
            return -1;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson);
        int lq = query(l, mid, lson, L, R);
        int rq = query(mid+1, r, rson, L, R);
        return find_lca(lq, rq);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;

    Seg1D st(n, arr);
    while (q--) {
        int op, l, r; cin >> op >> l >> r; l--, r--;
        if (op == 1) {
            st.modify(l, r);
        } else {
            cout << st.query(l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    build_phi_table();
    build_doubling();
    int T = 1;
    while (T--) {
        solve();
    }
}



