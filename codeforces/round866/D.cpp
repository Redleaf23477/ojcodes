#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Solver {
    int n;
    vector<vector<LL>> arr;
    Solver() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            vector<LL> tmp(2);
            cin >> tmp[0] >> tmp[1];
            arr.emplace_back(tmp);
        }
    }

    vector<pair<LL,LL>> ans;
    void try_try_see(char dir) {
        map<LL,multiset<LL>> by_row, by_col;
        for (int i = 0; i < n; i++) {
            by_row[arr[i][0]].insert(arr[i][1]);
            by_col[arr[i][1]].insert(arr[i][0]);
        }

        LL R = 0, C = 0, val = -1, prev1 = -1, prev2 = -1, acc = 0; 
        bool fixed_R = false, fixed_C = false;

        auto cleanup = [&](LL r, LL c) {
            by_col[c].erase(by_col[c].find(r));
            if (by_col[c].empty()) by_col.erase(c);

            by_row[r].erase(by_row[r].find(c));
            if (by_row[r].empty()) by_row.erase(r);
        };

        auto do_hori_cut = [&]() {
            LL used_c = by_col.rbegin()->first;
            LL used_r = *by_col.rbegin()->second.begin();
            val = used_c;
            if (!fixed_C) C += used_c;
            if (!fixed_R) R += used_r;
            cleanup(used_r, used_c);
            // update acc
            acc += used_r;
            // first hori cut fixs column
            fixed_C = true;
            // return the other size
            return used_r;
        };

        auto do_vert_cut = [&]() {
            LL used_r = by_row.rbegin()->first;
            LL used_c = *(by_row.rbegin()->second.begin());
            val = used_r;
            if (!fixed_R) R += used_r;
            if (!fixed_C) C += used_c;
            cleanup(used_r, used_c);
            // update acc
            acc += used_c;
            // first verti cut fixs row
            fixed_R = true;
            // return the other size
            return used_c;
        };

        bool AC = true;
        for (int used = 0; used < n && AC; used++) {
            // do I need to change direction?
            // if so, check if it is valid
            bool change = false;
            LL last_val = 0;
            LL last_acc = 0;
            if (dir == 'h') {
                if (by_col.empty() || by_col.rbegin()->first != val) {
                    dir = 'v';
                    change = true;
                    last_val = val;
                    last_acc = acc, acc = 0;
                }
            } else {
                if (by_row.empty() || by_row.rbegin()->first != val) {
                    dir = 'h';
                    change = true;
                    last_val = val;
                    last_acc = acc, acc = 0;
                }
            }
            // do cut
            LL tmp = 0;
            if (dir == 'h') tmp = do_hori_cut();
            else tmp = do_vert_cut();
            // check valid if change direction
            if (change) {
                if (prev1 != -1 && val + last_acc != prev1) {
                    // cerr << "!! val = " << val << ", last_acc = " << last_acc << ", prev1 = " << prev1 << endl;
                    AC = false;
                }
                prev1 = last_val;
            }

            /*
            cerr << "iteration " << used << ": " << endl;
            cerr << "dir = " << dir << endl;
            cerr << "R = " << R << ", C = " << C << ", val = " << val << ", tmp = " << tmp << endl;
            cerr << "prev1 = " << prev1 << ", prev2 = " << prev2 << endl;
            cerr << "acc = " << acc << ", AC = " << AC << endl;
            */
        }

        // final check
        if (prev1 != -1 && acc != prev1) {
            AC = false;
        }

        if (AC) {
            ans.emplace_back(R, C);
        }
    }
    void solve() {
        try_try_see('h');
        if (n != 1) try_try_see('v');
        cout << ans.size() << "\n";
        for (auto [R, C] : ans) {
            cout << R << " " << C << "\n";
        }
    };
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        Solver().solve();
    }
}



