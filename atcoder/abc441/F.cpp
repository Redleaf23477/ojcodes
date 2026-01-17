#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    const int NEG_INF = -1;
    size_t n, m; cin >> n >> m;
    vector<pair<LL, LL>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // val forward
    vector<vector<LL>> val(n + 1, vector<LL>(m + 1, NEG_INF));
    val[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        val[i][0] = 0;
        auto [p, v] = arr[i];
        for (int j = 1; j <= m; j++) {
            // take
            if (j - p >= 0) {
                val[i][j] = max(val[i][j], val[i - 1][j - p] + v);
            }
            // don't take
            val[i][j] = max(val[i][j], val[i - 1][j]);
        }
    }

    // find ans
    LL val_ans = *max_element(val[n].begin(), val[n].end());

    // val backtrack
    enum DpState {
        UNKNOWN,
        MUST_CHOOSE,
        MAYBE,
        MUST_NOT,
    };
    vector<DpState> ans(n + 1, UNKNOWN);

    vector<bool> bk_state(m + 1, false); {
        for (int j = 0; j <= m; j++) {
            if (val[n][j] == val_ans) {
                bk_state[j] = true;
            }
        }
    }

    vector<bool> nxt_bk_state(m + 1, false);
    for (int i = n; i > 0; i--) {
        auto [p, v] = arr[i];
        bool take = false, dont_take = false;

        for (int j = 0; j <= m; j++) {
            if (!bk_state[j]) continue;

            // is take?
            if (j - p >= 0 && val[i][j] == val[i - 1][j - p] + v) {
                take = true;
                nxt_bk_state[j - p] = true;
            }
            // is don't take?
            if (val[i][j] == val[i - 1][j]) {
                dont_take = true;
                nxt_bk_state[j] = true;
            }
        }

        if (take && dont_take) {
            ans[i] = MAYBE;
        } else if (take) {
            ans[i] = MUST_CHOOSE;
        } else if (dont_take) {
            ans[i] = MUST_NOT;
        } else {
            assert(false && "WTF");
        }

        bk_state.swap(nxt_bk_state);
        fill(nxt_bk_state.begin(), nxt_bk_state.end(), false);
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == MUST_CHOOSE) {
            cout << "A";
        } else if (ans[i] == MAYBE) {
            cout << "B";
        } else {
            cout << "C";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

