#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// better solution

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[i] <= arr[stk.top()]) stk.pop();
        if (stk.empty()) cout << 0 << " ";
        else cout << stk.top() + 1 << " ";
        stk.emplace(i);
    }
    cout << "\n";
}

/*
// Slow solution (segment tree)

struct Seg1D {
    int n;
    vector<int> st;
    Seg1D(int _n) : n(_n), st(4*n, -1) {}
    void modify(int l, int r, int idx, int x, int val) {
        if (l == r && r == x) {
            st[idx] = val; return;
        } else if (x < l || r < x) return;
        int mid = (l + r)/2, lson = idx * 2, rson = lson + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = max(st[lson], st[rson]);
    }
    void modify(int x, int val) {
        modify(0, n-1, 1, x, val);
    }
    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return st[idx];
        } else if (r < L || R < l) {
            return -1;
        }
        int mid = (l + r)/2, lson = idx * 2, rson = lson + 1;
        return max(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
    int query(int L, int R) {
        return query(0, n-1, 1, L, R);
    }
};

void relabel(vector<int> &arr) {
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    for (auto &x : arr) {
        x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    relabel(arr);

    Seg1D st(n);
    for (int i = 0; i < n; i++) {
        cout << st.query(0, arr[i]-1) + 1 << " ";
        st.modify(arr[i], i);
    }
    cout << "\n";
}
*/

