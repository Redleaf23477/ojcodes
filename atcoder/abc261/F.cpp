#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = pair<int,int>;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n), bit(n + 1, 0) {}
    int lowbit(int x) { return x & (-x); }
    int sum(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) {
            ans += bit[x];
        }
        return ans;
    }
    void modify(int x, int val) {
        for (; x <= n; x += lowbit(x)) {
            bit[x] += val;
        }
    }
};

LL right_lt(int N, vector<int> &X) {
    // use 1-index
    vector<P> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = make_pair(X[i], i + 1);
    }
    sort(arr.begin(), arr.end());
    LL ans = 0;
    BIT bit(N);
    for (auto [val, pos] : arr) {
        ans += bit.sum(N) - bit.sum(pos);
        bit.modify(pos, 1);
    }
    return ans;
}

LL right_lt_same_color(int N, vector<int> &C, vector<int> &X) {
    // use 1-index
    vector<vector<pair<int,int>>> color_pos(N + 1);
    for (int i = 0; i < N; i++) {
        color_pos[C[i]].emplace_back(X[i], i + 1);
    }
    LL ans = 0;
    BIT bit(N);
    for (int c = 1; c <= N; c++) {
        sort(color_pos[c].begin(), color_pos[c].end());
        for (auto [val, pos] : color_pos[c]) {
            ans += bit.sum(N) - bit.sum(pos);
            bit.modify(pos, 1);
        }
        for (auto [val, pos] : color_pos[c]) {
            bit.modify(pos, -1);
        }
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    vector<int> C(N), X(N);
    for (auto &x : C) cin >> x;
    for (auto &x : X) cin >> x;

    LL ans = right_lt(N, X) - right_lt_same_color(N, C, X);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



