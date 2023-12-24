#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using P = pair<int,int>;

struct BIT {
    int n;
    int lowbit(int x) { return x & (-x); }
    vector<int> bit;
    BIT(int _n) : n(_n), bit(n + 1, 0) {}
    void modify(int pos, int val) {
        for (; pos <= n; pos += lowbit(pos)) {
            bit[pos] += val;
        }
    }
    int query(int pos) {
        int sum = 0;
        for (; pos > 0; pos -= lowbit(pos)) {
            sum += bit[pos];
        }
        return sum;
    }
    int query(int L, int R) {
        return query(R) - query(L - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> arr(n + n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
        pos[arr[i]] = i;
    }
    vector<int> ans(n + n + 1);
    BIT bit(n + n + 1);
    for (int i = n + n; i > n; i--) {
        int dest = n + (i - n > arr[i]? arr[i] + n : arr[i]);
        if (dest >= n + n) continue;
        bit.modify(dest, 1);
    }
    for (int i = n; i > 0; i--) {
        int dest = (i > arr[i]? arr[i] + n : arr[i]);
        ans[arr[i]] = dest - i - bit.query(i, dest);
        bit.modify(dest, 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

