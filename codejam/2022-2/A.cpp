#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL N, K; cin >> N >> K;
    LL D = N * N - 1 - K;
    LL LV = (N + 1) / 2;

    // cerr << "D = " << D << endl;

    vector<LL> lv_start(LV, 1);
    for (LL k = LV-1, acc = 0; k >= 0; k--) {
        LL lv_size = 4 * k * 2;

        lv_start[k] += acc;
        acc += lv_size;
    }

    /*
    for (int i = LV-1; i >= 0; i--) {
        cerr << "lv_start[" << i << "] = " << lv_start[i] << endl;
    }
    */

    vector<int> shortcut_lv;
    for (int k = LV-1; k > 0; k--) {
        LL lv_size = 4 * k * 2;
        // cerr << "lv = " << k << ", lv_size = " << lv_size << ", D = " << D << endl;
        if (D >= lv_size - 8) {
            D -= lv_size - 8;
            shortcut_lv.emplace_back(k);
        }
    }
    int shortcut = shortcut_lv.size();

    // test if remaining D can be added with
    // #shortcut {6, 4, 2, 0}
    vector<int> delta {6, 4, 2, 0};
    vector<vector<int>> dp(shortcut+1, vector<int>(D+1, -1));  // dp[level][D] = move
    dp[0][0] = 0;
    for (int i = 1; i <= shortcut; i++) for (LL j = 0; j <= D; j++) {
        for (auto mv : {0, 1, 3, 2}) {
            LL jj = j - delta[mv];
            if (jj >= 0 && dp[i-1][jj] != -1) {
                dp[i][j] = mv;
            }
        }
    }

    auto make_move = [&](int mv, LL lv) {
        LL idx = 2 + lv * 2 * mv;
        LL new_idx = idx - 1 - 2 * mv;

        LL u = lv_start[lv] + idx - 1;
        LL v = lv_start[lv-1] + new_idx - 1;
        return make_tuple(u, v);
    };

    if (dp[shortcut][D] != -1) {
        vector<int> shortcut_arr;
        LL rem = D;
        for (int i = shortcut; i > 0; i--) {
            int mv = dp[i][rem];
            shortcut_arr.emplace_back(mv);
            rem -= delta[mv];
        }
        sort(shortcut_arr.begin(), shortcut_arr.end());

        if (shortcut_arr.back() == 3 && shortcut == LV - 1) {
            cout << "IMPOSSIBLE\n";
        }

        /*
        for (int i = 0; i < shortcut; i++) {
            cerr << "shortcut @ lv = " << shortcut_lv[i] << ", move = " << shortcut_arr[i] << endl;
        }
        */

        cout << shortcut << "\n";

        for (int j = 0; j < shortcut; j++) {
            LL lv = shortcut_lv[j];
            int mv = shortcut_arr[j];

            auto [u, v] = make_move(mv, lv);

            cout << u << " " << v << "\n";
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

