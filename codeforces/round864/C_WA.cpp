#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// int test_R, test_C, ans_r, ans_c;

int query(int r, int c) {
    cout << "? " << r << " " << c << endl;
    int res; cin >> res;
    /*
    int res = max(abs(r - ans_r), abs(c - ans_c));
    */
    return res;
}

void report(int r, int c) {
    if (r == ans_r && c == ans_c) {
        cerr << "AC on testcase:" << endl;
        cerr << "R = " << test_R << ", C = " << test_C << endl;
        cerr << "ans = (" << ans_r << ", " << ans_c << ")" << endl;
        return;
    } else {
        cerr << "WA on testcase:" << endl;
        cerr << "R = " << test_R << ", C = " << test_C << endl;
        cerr << "ans = (" << ans_r << ", " << ans_c << ")" << endl;
        cerr << "output = " << r << " " << c << endl;
        assert(false && "WA");
    }
    /*
    cout << "! " << r << " " << c << endl;
    return;
    */
}

using Seg = map<int,pair<int,int>>;

void print(Seg s, string axis) {
    cerr << axis << ": " << endl;
    for (auto [x, p] : s) {
        cerr << x << " -> (" << p.first << ", " << p.second << ")" << endl;
    }
}

void solve() {
    // int R, C; cin >> R >> C;
    int R = test_R, C = test_C;

    vector<pair<int,int>> Q;

    if (R >= 4 && C >= 3) {
        Q.emplace_back(1, 3);
        Q.emplace_back(2, 1);
        Q.emplace_back(4, 2);
    } else if (C >= 4 && R >= 3) {
        Q.emplace_back(3, 1);
        Q.emplace_back(1, 2);
        Q.emplace_back(2, 4);
    } else {
        Q.emplace_back(1, 1);
        Q.emplace_back(R, C);
        if (R >= C) Q.emplace_back(2, 1);
        else Q.emplace_back(1, 2);
    }

    int q1 = query(Q[0].first, Q[0].second);
    int q2 = query(Q[1].first, Q[1].second);
    int q3 = query(Q[2].first, Q[2].second);

    auto in_rect = [](pair<int,int> ep, Seg row, Seg col) {
        if (row.count(ep.first)) {
            if (row[ep.first].first <= ep.second && ep.second <= row[ep.first].second) {
                return true;
            }
        } 
        if (col.count(ep.second)) {
            if (col[ep.second].first <= ep.first && ep.first <= col[ep.second].second) {
                return true;
            }
        }
        return false;
    };

    auto build_rect = [&](int r, int c, int dist) {
        Seg row, col;
        vector<pair<int,int>> ep;
        // up, down
        for (auto rr : {r - dist, r + dist}) {
            if (1 <= rr && rr <= R) {
                row[rr] = make_pair(max(1, c - dist), min(C, c + dist));
                ep.emplace_back(rr, row[rr].first);
                ep.emplace_back(rr, row[rr].second);
            }
        }
        // left, right
        for (auto cc : {c - dist, c + dist}) {
            if (1 <= cc && cc <= C) {
                col[cc] = make_pair(max(1, r - dist), min(R, r + dist));
                ep.emplace_back(col[cc].first, cc);
                ep.emplace_back(col[cc].second, cc);
            }
        }
        return make_tuple(row, col, ep);
    };

    auto intersect = [](Seg r1, Seg c1, Seg r2, Seg c2) {
        Seg row, col;
        vector<pair<int,int>> ep;
        // row
        for (auto it1 = r1.begin(), it2 = r2.begin(); it1 != r1.end() && it2 != r2.end(); ) {
            if (it1->first == it2->first) {
                int L = max(it1->second.first, it2->second.first);
                int R = min(it1->second.second, it2->second.second);
                if (L <= R) {
                    row[it1->first] = make_pair(L, R);
                    ep.emplace_back(it1->first, L);
                    ep.emplace_back(it1->first, R);
                }
                it1++, it2++;
            } else if (it1->first < it2->first) {
                it1++;
            } else {
                it2++;
            }
        }
        // col
        for (auto it1 = c1.begin(), it2 = c2.begin(); it1 != c1.end() && it2 != c2.end(); ) {
            if (it1->first == it2->first) {
                int L = max(it1->second.first, it2->second.first);
                int R = min(it1->second.second, it2->second.second);
                if (L <= R) {
                    col[it1->first] = make_pair(L, R);
                    ep.emplace_back(L, it1->first);
                    ep.emplace_back(R, it1->first);
                }
                it1++, it2++;
            } else if (it1->first < it2->first) {
                it1++;
            } else {
                it2++;
            }
        }
        return make_tuple(row, col, ep);
    };

    auto [r1, c1, ep1] = build_rect(Q[0].first, Q[0].second, q1);
    auto [r2, c2, ep2] = build_rect(Q[1].first, Q[1].second, q2);
    auto [r3, c3, ep3] = build_rect(Q[2].first, Q[2].second, q3);

    /*
    cerr << "(1, 3) : " << endl;
    print(r1, "row"), print(c1, "col");
    cerr << "(2, 1) : " << endl;
    print(r2, "row"), print(c2, "col");
    cerr << "(4, 2) : " << endl;
    print(r3, "row"), print(c3, "col");
    */

    auto [ra, ca, ep4] = intersect(r1, c1, r2, c2);
    auto [rb, cb, ep5] = intersect(ra, ca, r3, c3);

    /*
    cerr << "intersect 1, 2 : " << endl;
    print(ra, "row"), print(ca, "col");
    cerr << "intersect 3 : " << endl;
    print(rb, "row"), print(cb, "col");
    */

    if (!rb.empty()) {
        report(rb.begin()->first, rb.begin()->second.first);
        return;
    } else if (!cb.empty()) {
        report(cb.begin()->second.first, cb.begin()->first);
        return;
    } else {
        for (auto epi : {ep1, ep2, ep3, ep4, ep5}) {
            for (auto ep : epi) {
                if (in_rect(ep, r1, c1) && in_rect(ep, r2, c2) && in_rect(ep, r3, c3)) {
                    report(ep.first, ep.second);
                    return;
                }
            }
        }
    }

    cerr << "No output on testcase: " << endl;
    cerr << "R = " << test_R << ", C = " << test_C << endl;
    cerr << "ans = (" << ans_r << ", " << ans_c << ")" << endl;
    assert(false && "Idle");
}

int main() {
    for (test_R = 1; test_R < 10; test_R++) {
        for (test_C = 1; test_C < 10; test_C++) {
            for (ans_r = 1; ans_r <= test_R; ans_r++) {
                for (ans_c = 1; ans_c <= test_C; ans_c++) {
                    solve();
                }
            }
        }
    }
    /*
    int T; cin >> T;
       while (T--) {
       solve();
       }
       */
}



