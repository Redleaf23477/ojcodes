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
    LL ans = 0;
    for (int num = 1; num <= n; num++) {
        int p = num - (bit.query(n) - bit.query(num - 1));
        cerr << "num = " << num << ", p = " << p << ", add = " << abs(pos[p] - (num - 1)) << endl;
        ans += abs(pos[p] - (num - 1));
        cerr << "bit.add(" << arr[num-1] + bit.query(arr[num-1]) << ")" << endl;
        bit.add(arr[num-1] + bit.query(arr[num-1]), 1);
    }
    cout << ans << "\n";
}

