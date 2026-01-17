#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct BIT {
    int n;
    vector<int> bit;

    int lowbit(int x) {
        return x & (-x);
    }

    BIT(int _n) : n(_n), bit(n + 1, 0) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += lowbit(pos)) {
            bit[pos] += val;
        }
    }

    int query(int pos) {
        int acc = 0;
        for (; pos > 0; pos -= lowbit(pos)) {
            acc += bit[pos];
        }
        return acc;
    }
};

void solve() {
    size_t n; cin >> n;
    vector<int> arr(n); {
        string s; cin >> s;
        for (size_t i = 0; i < n; i++) {
            if (s[i] == 'A') arr[i] = 1;
            else if (s[i] == 'B') arr[i] = -1;
            else arr[i] = 0;
        }
    }

    // mp[i] = j; # of prefix with sum i = j
    int bit_offset = n + 1;
    BIT bit(n + bit_offset); {
        int acc = 0;
        for (auto x : arr) {
            acc += x;
            bit.update(acc + bit_offset, 1);
        }
    }
    int prefix_offset = 0;
    LL ans = 0;
    for (size_t i = 0; i < n; i++) {
        // update answer: how many entries is > prefix_offset
        ans += bit.query(n + bit_offset) - bit.query(prefix_offset + bit_offset);
        
        // update offset
        prefix_offset += arr[i];
        bit.update(prefix_offset + bit_offset, -1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

