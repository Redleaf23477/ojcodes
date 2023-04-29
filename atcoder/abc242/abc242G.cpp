#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Query = tuple<int,int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int q; cin >> q;
    int k = sqrt(q);
    vector<Query> qry(q);
    for (int i = 0; i < q; i++) {
        auto &[l, r, idx] = qry[i];
        cin >> l >> r; l--, r--;
        idx = i;
    }
    sort(qry.begin(), qry.end(), [k](const Query &lhs, const Query &rhs) {
        auto [l1, r1, i1] = lhs;
        auto [l2, r2, i2] = rhs;
        int b1 = l1 / k, b2 = l2 / k;
        if (b1 != b2) return b1 < b2;
        else if (r1 != r2) return r1 < r2;
        else return i1 < i2;
    });

    // mo's algo
    vector<int> cnt(*max_element(arr.begin(), arr.end()) + 1, 0);
    vector<int> qry_ans(q, -1);
    int ans = 0, l = 0, r = -1;
    auto update = [&](int iq, int elem, int val) {
        if (val == 1 && cnt[elem] % 2 == 1) ans += 1;
        if (val == -1 && cnt[elem] % 2 == 0) ans -= 1;
        cnt[elem] += val;
    };
    for (const auto &[lq, rq, iq] : qry) {
        for (; r < rq; r++) update(iq, arr[r+1], 1);
        for (; lq < l; l--) update(iq, arr[l-1], 1);
        for (; rq < r; r--) update(iq, arr[r], -1);
        for (; l < lq; l++) update(iq, arr[l], -1);
        qry_ans[iq] = ans;
    }

    for (auto x : qry_ans) cout << x << "\n";
}

