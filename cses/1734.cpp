#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int relabel(vector<int> &arr) {
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());
    auto it = unique(tmp.begin(), tmp.end());
    tmp.erase(it, tmp.end());
    for (auto &x : arr) {
        x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
    }
    return tmp.size();
}

struct BIT {
    int n;
    vector<int> bit;

    int lowbit(int x) { return x & -x; }
    void modify(int x, int val) {
        for (; x <= n; x += lowbit(x)) {
            bit[x] += val;
        }
    }
    int query(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) ans += bit[x];
        return ans;
    }

    BIT(int _n) : n(_n), bit(n+1, 0) {}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int uniq_elem = relabel(arr);

    using Q = tuple<int,int,int>;
    vector<Q> query(q);
    for (int i = 0; i < q; i++) {
        auto &[l, r, idx] = query[i];
        cin >> l >> r;
        idx = i;
    }
    sort(query.begin(), query.end());

    vector<int> nxt(n, -1), buff(uniq_elem, -1);
    for (int i = n-1; i >= 0; i--) {
        nxt[i] = buff[arr[i]];
        buff[arr[i]] = i+1;
    }

    vector<int> ans(q);
    BIT bit(n+1);
    for (int i = 0; i < uniq_elem; i++) {
        if (buff[i] != -1) bit.modify(buff[i], 1);
    }
    int L = 1;
    for (auto [l, r, idx] : query) {
        for (; L < l; L++) {
            bit.modify(L, -1);
            if (nxt[L-1] != -1) bit.modify(nxt[L-1], 1);
        }
        ans[idx] = bit.query(r);
    }

    for (auto x : ans) cout << x << "\n";
}