#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Stack = stack<int, vector<int>>;

struct BlockDecomposition {
    struct BigBlock { 
        Stack complete, partial;
    };
    int n;
    int block_len;
    vector<BigBlock> big_blocks;
    vector<Stack> small_blocks;
    vector<bool> is_popped;
    BlockDecomposition(int _n, int q): n(_n), block_len(sqrt(n)), big_blocks(n / block_len + 1), small_blocks(n), is_popped(q, false) {}
    void push(int val, int l, int r) {
        if (l % block_len != 0) big_blocks[l / block_len].partial.emplace(val);
        if (r != n-1 && r % block_len != block_len - 1) big_blocks[r / block_len].partial.emplace(val);
        for (int i = l; i <= r; ) {
            if (i % block_len == 0 && i + block_len - 1 <= r) {
                big_blocks[i / block_len].complete.emplace(val);
                i += block_len;
            } else {
                small_blocks[i].emplace(val);
                i++;
            }
        }
    }
    int get_real_top(Stack &stk) {
        int ans = -1;
        while (!stk.empty() && is_popped[stk.top()]) stk.pop();
        if (!stk.empty()) ans = stk.top();
        return ans;
    }
    int query(int l, int r) {
        int ans = -1;
        if (l % block_len != 0) ans = max(ans, get_real_top(big_blocks[l / block_len].complete));
        if (r != n-1 && r % block_len != block_len - 1) ans = max(ans, get_real_top(big_blocks[r / block_len].complete));
        for (int i = l; i <= r; ) {
            if (i % block_len == 0 && i + block_len - 1 <= r) {
                auto &B = big_blocks[i / block_len];
                ans = max({ans, get_real_top(B.complete), get_real_top(B.partial)});
                i += block_len;
            } else {
                ans = max(ans, get_real_top(small_blocks[i]));
                i++;
            }
        }
        // mark pop and return answer
        if (ans != -1) is_popped[ans] = true;
        return ans;
    }
};

void read_query(int n, int q, vector<string> &int2str, vector<tuple<int,int,int,int>> &queries) {
    vector<int> to_relabel;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            string name; cin >> name;
            int l, r; cin >> l >> r;
            int idx = int2str.size();
            int2str.emplace_back(name);
            queries[i] = make_tuple(op, l, r, idx);
            to_relabel.emplace_back(l), to_relabel.emplace_back(r);
        } else {
            int l, r; cin >> l >> r;
            queries[i] = make_tuple(op, l, r, -1);
            to_relabel.emplace_back(l), to_relabel.emplace_back(r);
        }
    }
    sort(to_relabel.begin(), to_relabel.end());
    auto it = unique(to_relabel.begin(), to_relabel.end());
    to_relabel.erase(it, to_relabel.end());
    for (auto &[op, l, r, idx] : queries) {
        l = lower_bound(to_relabel.begin(), to_relabel.end(), l) - to_relabel.begin();
        r = lower_bound(to_relabel.begin(), to_relabel.end(), r) - to_relabel.begin();
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vector<string> int2str;
    vector<tuple<int,int,int,int>> queries(q);
    read_query(n, q, int2str, queries);

    BlockDecomposition block(n, int2str.size());
    for (auto &[op, l, r, idx] : queries) {
        if (op == 1) {
            block.push(idx, l, r);
        } else {
            int ans = block.query(l, r);
            if (ans == -1) cout << ">_<\n";
            else cout << int2str[ans] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

