#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct SparseTable {
    int n, lg_n;
    vector<int> arr;
    vector<vector<int>> st;
    void init(vector<int> const &data) {
        arr = data;
        n = arr.size();
        lg_n = __lg(n) + 1;
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        st.assign(lg_n + 1, idx);
        for (int lg = 1; lg <= lg_n; lg++) {
            for (int i = 0; i < n; i++) {
                int j = min(n - 1, i + (1 << (lg - 1)));
                int lhs = arr[st[lg - 1][i]];
                int rhs = arr[st[lg - 1][j]];
                if (lhs <= rhs) st[lg][i] = st[lg - 1][j];
                else st[lg][i] = st[lg - 1][i];
            }
        }
    }
    int query(int l, int r) {
        if (r < l) return -1;
        int len = r - l + 1;
        int lg_len = __lg(len);
        int i = st[lg_len][l], j = st[lg_len][r - (1 << lg_len) + 1];
        if (arr[i] < arr[j]) return j;
        else return i;
    }
};

struct Player {
    int size;
    vector<int> atk, def;
    SparseTable t_def;
    Player(int n) : size(n), atk(n), def(n) {
        vector<pair<int,int>> arr(size);
        for (auto &[x, y] : arr) cin >> x;
        for (auto &[x, y] : arr) cin >> y;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < size; i++) {
            tie(atk[i], def[i]) = arr[i];
        }
        t_def.init(def);
    }
    int query(int x) {
        int l = upper_bound(atk.begin(), atk.end(), x) - atk.begin();
        return t_def.query(l, size - 1);
    }
};


void solve() {
    int n; cin >> n;
    Player A(n);
    int m; cin >> m;
    Player B(m);

    vector<int> to(n + m, -1);
    for (int i = 0; i < n; i++) {
        to[i] = B.query(A.def[i]);
        if (to[i] != -1) to[i] += n;
    }
    for (int i = 0; i < m; i++) {
        to[n + i] = A.query(B.def[i]);
    }

    // topo sort
    const int NO_VIS = -2;
    vector<int> winner(n + m, NO_VIS);
    vector<bool> instk(n + n, false);
    function<int(int)> dfs = [&](int u) {
        instk[u] = true;
        if (to[u] == -1) {
            winner[u] = u;
        } else if (winner[to[u]] != NO_VIS) {
            winner[u] = winner[to[u]];
        } else {
            int v = to[u];
            if (instk[v]) {
                winner[u] = -1;
            } else {
                winner[u] = dfs(v);
            }
        }
        instk[u] = false;
        return winner[u];
    };
    for (int i = 0; i < n; i++) {
        if (winner[i] == NO_VIS) {
            dfs(i);
        }
    }

    int win = 0, tie = 0, lose = 0;
    for (int i = 0; i < n; i++) {
        if (winner[i] == -1) tie += 1;
        else if ((winner[i] < n) == (i < n)) win += 1;
        else lose += 1;
    }
    cout << win << " " << tie << " " << lose << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

