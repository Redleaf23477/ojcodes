#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL k; cin >> k;
    vector<pair<LL,LL>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    LL ans = -1;
    LL step_cnt = 0, len1 = 0, acc = 0;
    LL cursor = 0;
    for (auto [l, r] : arr) {
        // move cursor
        step_cnt += l - cursor;
        cursor = l;
        if (acc < k) {
            // I must use the next segment
            // down shift
            step_cnt += 1;
            // move right
            LL move = min(k - acc, r - l + 1);
            LL bye1 = min(len1, r - l + 1 - move);
            // cerr << ".. " << move << ", " << bye1 << endl;
            step_cnt += move + bye1 - 1;
            step_cnt -= 2 * bye1;
            cursor += move + bye1 - 1;
            len1 -= bye1;
            acc += move;
            // count if this segment has length 1
            if (r - l + 1 == 1) {
                len1++;
            }
            // up shift
            step_cnt += 1;
            // update answer
            if (acc == k && (ans == -1 || ans > step_cnt)) {
                ans = step_cnt;
            }
        } else if (acc == k) {
            // substitute len1
            if (r - l + 1 != 1 && len1 > 0) {
                // down shift
                step_cnt += 1;
                // move
                LL bye1 = min(len1, r - l + 1);
                step_cnt += bye1 - 1;
                cursor += bye1 - 1;
                len1 -= bye1;
                // replace len1 (down and up) shift
                step_cnt -= 2 * bye1;
                // up shift
                step_cnt += 1;
            }
            // update answer
            if (ans == -1 || ans > step_cnt) {
                ans = step_cnt;
            }
        }
        /*
        cerr << ".. cur = " << cursor << ", step = " << step_cnt
            << ", acc = " << acc << ", len1 = " << len1 << endl;
            */
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



