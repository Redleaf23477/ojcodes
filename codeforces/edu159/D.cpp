#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using MP = map<pair<int,int>, vector<int>>;

void solve() {
    int n, q; cin >> n >> q;
    string cmd; cin >> cmd;
    string rev(cmd); reverse(rev.begin(), rev.end());

    MP cmd_map, rev_map;
    vector<pair<int,int>> cmd_pos(n), rev_pos(n);
    auto init = [&](string &cmd, MP &mp, vector<pair<int,int>> &pos) {
        for (int i = 0, x = 0, y = 0; i < n; i++) {
            int ch = cmd[i];
            if (ch == 'U') y++;
            else if (ch == 'D') y--;
            else if (ch == 'L') x--;
            else x++;
            mp[make_pair(x, y)].emplace_back(i);
            pos[i] = make_pair(x, y);
        }
    };
    init(cmd, cmd_map, cmd_pos);
    init(rev, rev_map, rev_pos);

    /*
    cerr << "cmd: ";
    for (auto [x, y] : cmd_pos) {
        cerr << "(" << x << ", " << y << ")";
    }
    cerr << endl;
    cerr << "rev: ";
    for (auto [x, y] : rev_pos) {
        cerr << "(" << x << ", " << y << ")";
    }
    cerr << endl;
    */

    auto subquery = [&](int qx, int qy, int l, int r, MP &mp) {
        auto it = mp.find(make_pair(qx, qy));
        if (it == mp.end()) return false;

        vector<int> &pos = it->second;
        auto lb = lower_bound(pos.begin(), pos.end(), l);
        auto ub = upper_bound(pos.begin(), pos.end(), r);
        return ub > lb;
    };

    while (q--) {
        int x, y; cin >> x >> y;
        int l, r; cin >> l >> r; l--, r--;

        if (x == 0 && y == 0) {
            cout << "YES\n"; continue;
        }

        // first segment
        int me_x = 0, me_y = 0;
        int qx = x, qy = y;
        /*
        cerr << "subquery(" << qx << ", " << qy << ", " << 0 << ", " << l - 1 << ", cmd_map)" << endl;
        */
        if (l - 1 >= 0 && subquery(qx, qy, 0, l - 1, cmd_map)) {
            cout << "YES\n"; continue;
        }

        // reversed segment
        if (l != 0) {
            tie(me_x, me_y) = cmd_pos[l - 1];
        }
        int dx = x - me_x, dy = y - me_y;
        /*
        cerr << "[rev] : me = (" << me_x << ", " << me_y << "), d = (" << dx << ", " << dy << ")" << endl;
        */
        if (n - 1 - r != 0) {
            tie(qx, qy) = rev_pos[n - 1 - r - 1];
            /*
            cerr << "..Q = (" << qx << ", " << qy << ")" << endl;
            */
        } else {
            qx = qy = 0;
            /*
            cerr << "..Q = (" << qx << ", " << qy << ")" << endl;
            */
        }
        me_x += rev_pos[n - 1 - l].first - qx, me_y += rev_pos[n - 1 - l].second - qy;
        qx += dx, qy += dy;

        /*
        cerr << "subquery(" << qx << ", " << qy << ", " << n - 1 - r << ", " << n - 1 - l << ", rev_map)" << endl;
        */
        if (subquery(qx, qy, n - 1 - r, n - 1 - l, rev_map)) {
            cout << "YES\n"; continue;
        }

        // last segment
        dx = x - me_x, dy = y - me_y;
        tie(qx, qy) = cmd_pos[r];
        qx += dx, qy += dy;
        /*
        cerr << "[last] : me = (" << me_x << ", " << me_y << "), d = (" << dx << ", " << dy << ")" << endl;
        cerr << "subquery(" << qx << ", " << qy << ", " << r + 1 << ", " << n - 1 << ", cmd_map)" << endl;
        */
        if (r + 1 < n && subquery(qx, qy, r + 1, n - 1, cmd_map)) {
            cout << "YES\n"; continue;
        }

        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

