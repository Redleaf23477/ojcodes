#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n), bit(n+1, 0) {}
    int lowbit(int x) { return x & (-x); }
    void add(int pos, int val) {
        for (; pos <= n; pos += lowbit(pos)) {
            bit[pos] += val;
        }
    }
    int query(int pos) {
        int ans = 0;
        for (; pos > 0; pos -= lowbit(pos)) {
            ans += bit[pos];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n), pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    BIT bit(n);
    for (int i = 1; i <= n; i++) bit.add(i, 1);
    vector<bool> bye(n+1, false);
    LL ans = 0;
    int smallest = 1;
    for (int num = 1; num <= n; num++) {
        int rk_dest = bit.query(arr[num-1]);
        while (bye[smallest]) smallest++;
        int rk_smallest = bit.query(smallest);
        ans += abs(rk_dest - rk_smallest);
        bye[arr[num-1]] = true;
        bit.add(arr[num-1], -1);
    }
    cout << ans << "\n";
}

