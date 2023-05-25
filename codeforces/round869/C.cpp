#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n+2, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[n+1] = 1'000'000'009;
    vector<int> cnt(n+3, 0), sum(n+3, 0);
    map<int,int> fwd_seg, back_seg;
    for (int i = 1, combo = 0; i <= n+1; i++) {
        if (arr[i] > arr[i-1]) {
            if (combo >= 2) {
                combo += 1;
                // flush combo
                int l = i - combo;
                int r = i-1;
                fwd_seg[l] = r, back_seg[r] = l;
                cnt[l] += 1;
                sum[l] += combo;
            }
            combo = 0;
        } else {
            // accumulate combo
            combo++;
        }
    }
    /*
    cerr << "cnt" << endl;
    for (int i = 1; i <= n+1; i++) cerr << cnt[i] << " ";
    cerr << endl;
    cerr << "sum" << endl;
    for (int i = 1; i <= n+1; i++) cerr << sum[i] << " ";
    cerr << endl;
    */

    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    partial_sum(sum.begin(), sum.end(), sum.begin());

    
    /*
    cerr << "cnt" << endl;
    for (int i = 1; i <= n+1; i++) cerr << cnt[i] << " ";
    cerr << endl;
    cerr << "sum" << endl;
    for (int i = 1; i <= n+1; i++) cerr << sum[i] << " ";
    cerr << endl;
    */


    while (q--) {
        int L, R; cin >> L >> R;
        int ans = R - L + 1;
        ans -= sum[R] - sum[L-1];
        ans += 2 * (cnt[R] - cnt[L-1]);
        // deal back
        auto b = fwd_seg.upper_bound(R);
        if (b != fwd_seg.begin()) {
            b--;
            int seg_l = b->first;
            int seg_r = b->second;
            if (seg_r > R && seg_l >= L) {
                // redo
                ans += seg_r - seg_l + 1;
                ans -= 2;
                // re-calc
                if (R - seg_l + 1 > 2) {
                    ans -= R - seg_l + 1;
                    ans += 2;
                }
            }
        }
        // deal front
        auto f = back_seg.lower_bound(L);
        if (f != back_seg.end()) {
            int seg_l = f->second;
            int seg_r = f->first;
            if (seg_l < L && seg_r <= R && seg_r - L + 1 > 2) {
                ans -= seg_r - L + 1;
                ans += 2;
            }
        }
        // deal included
        f = fwd_seg.upper_bound(L);
        if (f != fwd_seg.begin()) {
            f--;
            int seg_l = f->first;
            int seg_r = f->second;
            if (seg_l <= L && R <= seg_r) {
                ans = min(R - L + 1, 2);
            }
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



