#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct SegList {
    LL union_length;
    vector<pair<LL,LL>> seg;

    void update_seg(LL L, LL R) {
        // union [L, r] into seg
        while (!seg.empty()) {
            auto [seg_l, seg_r] = seg.back();
            if (seg_r < R) {
                union_length -= seg_r - seg_l;
                seg.pop_back();
            } else if (R < seg_l) {
                seg.emplace_back(L, R);
                union_length += R - L;
                return;
            } else {
                union_length -= seg_r - seg_l;
                seg.pop_back();
                seg.emplace_back(L, seg_r);
                union_length += seg_r - L;
                return;
            }
        }
        seg.emplace_back(L, R);
        union_length += R - L;
    }
    LL get_sum() { return union_length; }
    void print() {
        for (auto [l, r] : seg) cerr << "[" << l << "," << r << "]";
    }
};

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> gt(n);
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= i; j--) {
            if (arr[i] > arr[j]) {
                gt[i].emplace_back(j);
            }
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cerr << "gt[" << i << "] = ";
        for (auto x : gt[i]) cerr << x << " ";
        cerr << endl;
    }
    */

    LL sum = 0;
    // seg ending at some r
    vector<SegList> seg(n);
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            // seg[r]: segs in range [l+1 : r]
            // update seg r
            if (!gt[l].empty() && gt[l].back() <= r) {
                while (gt[l].size() > 1 && gt[l].end()[-2] <= r) gt[l].pop_back();
                seg[r].update_seg(l, gt[l].back());
            }

            /*
            cerr << "l = " << l << ", r = " << r << ", seg = ";
            seg[r].print();
            cerr << ", union = " << seg[r].get_sum() << endl;
            */

            sum += seg[r].get_sum();
        }
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



