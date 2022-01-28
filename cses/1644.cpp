#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n), bit(n+1, 0) { };
    int lowbit(int x) { return x & -x; }
    void modify(int p, int v) {
        for (; p <= n; p += lowbit(p)) {
            bit[p] += v;
        }
    }
    LL query(int p) {
        LL ans = 0;
        for (; p; p -= lowbit(p)) {
            ans += bit[p];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL L, R; cin >> L >> R;

    vector<LL> arr(n); 
    for (auto &x : arr) cin >> x;
    partial_sum(arr.begin(), arr.end(), arr.begin());

    vector<LL> uniq(arr);
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    cerr << "uniq = ";
    for (auto u : uniq) cerr << u << " ";
    cerr << endl;

    LL ans = 0;
    BIT bit(uniq.size());
    for (auto s : arr) {
        LL l = s - R, r = s - L;
        l = lower_bound(uniq.begin(), uniq.end(), l) - uniq.begin() + 1;
        r = upper_bound(uniq.begin(), uniq.end(), r) - uniq.begin();
        cerr << "s = " << s << ", s-R = " << s - R << ", s-L = " << s - L << ", l = " << l << ", r = " << r << " ";
        if (l <= r) {
            if (l == 0) {
                ans += 1 + bit.query(r);
                cerr << 1 + bit.query(r) << " ";
            } else {
                ans += bit.query(r) - bit.query(l-1);
                cerr << bit.query(r) - bit.query(l-1) << "\n";
            }
        } else {
            cerr << "x\n";;
        }
        s = lower_bound(uniq.begin(), uniq.end(), s) - uniq.begin() + 1;
        bit.modify(s, 1);
    }
    cerr << "\n";
    cout << ans << "\n";
}

