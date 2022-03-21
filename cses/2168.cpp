#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void relabel(vector<tuple<int,int,int>> &arr) {
    vector<int> s(2 * arr.size()); 
    for (size_t i = 0; i < arr.size(); i++) {
        auto &[l, r, idx] = arr[i];
        s[2*i] = l, s[2*i+1] = r;
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (auto &[l, r, idx] : arr) {
        l = lower_bound(s.begin(), s.end(), l) - s.begin() + 1;
        r = lower_bound(s.begin(), s.end(), r) - s.begin() + 1;
    }
}

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n+1), bit(n, 0) { }
    int lowbit(int x) { return x & -x; }
    void modify(int x, int val) {
        for (; x < n; x += lowbit(x)) {
            bit[x] += val;
        }
    }
    int query(int x) {
        int sum = 0;
        for (; x; x -= lowbit(x)) {
            sum += bit[x];
        }
        return sum;
    }
};

void ans1(int n, vector<tuple<int,int,int>> &arr) {
    vector<int> ans(n, -1);
    BIT bit(2*n);
    for (int i = n-1; i >= 0; i--) {
        auto [l, r, idx] = arr[i];
        ans[idx] = bit.query(r);
        bit.modify(r, 1);
    }
    for (auto x : ans) {
        cout << (x > 0) << " ";
    }
    cout << "\n";
}

void ans2(int n, vector<tuple<int,int,int>> &arr) {
    vector<int> ans(n, -1);
    BIT bit(2*n);
    vector<vector<int>> tag(2*n+2);
    for (int i = 0, p = 0; p <= 2*n+1; p++) {
        // rip up
        while (!tag[p].empty()) {
            auto [l, r, idx] = arr[tag[p].back()]; tag[p].pop_back();
            bit.modify(l, -1);
            ans[idx] = bit.query(l);
        }
        // add
        while (i < n && get<0>(arr[i]) == p) {
            auto [l, r, idx] = arr[i];
            tag[r].emplace_back(i);
            bit.modify(l, 1);
            i += 1;
        }
    }
    for (auto x : ans) {
        cout << (x > 0) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<tuple<int,int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        auto &[l, r, idx] = arr[i];
        cin >> l >> r;
        idx = i;
    }
    relabel(arr);

    // #ranges a range contains
    sort(arr.begin(), arr.end(), [](const tuple<int,int,int> &lhs, const tuple<int,int,int> &rhs) {
        auto [l1, r1, i1] = lhs;
        auto [l2, r2, i2] = rhs;
        return l1 < l2 || (l1 == l2 && (r1 > r2));
    });
    ans1(n, arr);

    // #ranges contained by a range
    sort(arr.begin(), arr.end(), [](const tuple<int,int,int> &lhs, const tuple<int,int,int> &rhs) {
        auto [l1, r1, i1] = lhs;
        auto [l2, r2, i2] = rhs;
        return l1 < l2 || (l1 == l2 && (r1 < r2));
    });
    ans2(n, arr);
}

