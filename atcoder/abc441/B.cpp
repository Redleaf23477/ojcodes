#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    size_t n, m; cin >> n >> m;
    vector<bool> s_set(26, false); {
        string s; cin >> s;
        for (auto ch : s) {
            s_set[ch - 'a'] = true;
        }
    }
    vector<bool> t_set(26, false); {
        string t; cin >> t;
        for (auto ch : t) {
            t_set[ch - 'a'] = true;
        }
    }
    size_t q; cin >> q;
    while (q--) {
        string w; cin >> w;
        bool is_s = true;
        bool is_t = true;
        for (auto ch : w) {
            if (s_set[ch - 'a'] == false) {
                is_s = false;
            }
            if (t_set[ch - 'a'] == false) {
                is_t = false;
            }
        }

        if ((is_s ^ is_t) == false) {
            cout << "Unknown\n";
        } else if (is_s) {
            cout << "Takahashi\n";
        } else /* if (is_t) */ {
            cout << "Aoki\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

