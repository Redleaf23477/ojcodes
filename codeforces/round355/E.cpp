#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr double lg3 = log2(3.0);
constexpr LL MOD = 1e9+7;
constexpr int INF = 48763;

// vector<pair<int,int>> dir {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, 
//                            {0, 1}, {1, 1}, {1, 0}, {1, -1}};
vector<int> dr {0, -1, -1, -1, 0, 1, 1, 1};
vector<int> dc {-1, -1, 0, 1, 1, 1, 0, -1};
bool is_dir_cross(int d) { return d % 2 == 0; }
bool is_dir_x(int d) { return d % 2 == 1; }

bool bigger(vector<int> test, vector<int> ans) {
    if (test[0] > 0) return false;
    else if (ans[0] > 0) return true;

    int more_2 = test[2] - ans[2];
    int more_3 = test[3] - ans[3];
    if (more_2 > 0 && more_3 > 0) {
        return true;
    } else if (more_2 <= 0 && more_3 <= 0) {
        return false;
    } else if (more_2 > 0) {
        return more_2 > lg3 * (-more_3);
    } else {
        return lg3 * more_3 > (-more_2);
    }
}

LL calc(vector<int> ans) {
    LL prod = 1;
    if (ans[0] > 0) prod = 0;
    for (int num = 2; num <= 3; num++) {
        for (int cnt = 0; cnt < ans[num]; cnt++) {
            prod = prod * num % MOD;
        }
    }
    return prod;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char ch; cin >> ch;
            arr[r][c] = ch - '0';
        }
    }

    auto legal = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    };

    auto iterate = [&](function<void(int,int,int)> task) {
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            for (int dir = 0; dir < 4; dir++) {
                task(r, c, dir);
            }
        }
        for (int r = n-1; r >= 0; r--) for (int c = n-1; c >= 0; c--) {
            for (int dir = 4; dir < 8; dir++) {
                task(r, c, dir);
            }
        }
    };

    // step 1: calculate radius
    auto step1 = [&]() {
        vector<vector<int>> rad_cross(n, vector<int>(n, INF));
        vector<vector<int>> rad_x(n, vector<int>(n, INF));
        vector<vector<vector<int>>> rad_pref(8, vector<vector<int>>(n, vector<int>(n, 0)));
        auto get_radius = [&](int r, int c, int dir) {
            int pr = r + dr[dir], pc = c + dc[dir];
            if (legal(pr, pc)) rad_pref[dir][r][c] = rad_pref[dir][pr][pc];

            if (arr[r][c] == 0) rad_pref[dir][r][c] = 0;
            else rad_pref[dir][r][c] += 1;

            if (is_dir_cross(dir)) rad_cross[r][c] = min(rad_cross[r][c], rad_pref[dir][r][c]);
            else rad_x[r][c] = min(rad_x[r][c], rad_pref[dir][r][c]);
        };
        iterate(get_radius);
        return make_pair(rad_cross, rad_x);
    };
    auto [rad_cross, rad_x] = step1();
    /*
       for (int r = 0; r < n; r++) {
       for (int c = 0; c < n; c++) {
       cerr << "(" << rad_cross[r][c] << "," << rad_x[r][c] << ") ";
       }
       cerr << endl;
       }
       */

    // step 2: calculate cross 
    vector<vector<vector<vector<int>>>> val_pref(8, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(4, 0))));
    auto calc_pref = [&](int r, int c, int dir) {
        int pr = r + dr[dir], pc = c + dc[dir];
        val_pref[dir][r][c][arr[r][c]] += 1;
        if (legal(pr, pc)) {
            for (int i = 0; i < 4; i++) {
                val_pref[dir][r][c][i] += val_pref[dir][pr][pc][i];
            }
        }
    };
    iterate(calc_pref);

    // step 3: output answer
    vector<int> ans {1, 0, 0, 0};
    for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
        vector<int> cross(4, 0), x(4, 0);
        cross[arr[r][c]] -= 3;
        x[arr[r][c]] -= 3;
        for (int dir = 0; dir < 8; dir++) {
            if (is_dir_cross(dir)) {
                int rad = rad_cross[r][c];
                int pr = r + rad * dr[dir], pc = c + rad * dc[dir];
                for (int i = 0; i < 4; i++) {
                    cross[i] += val_pref[dir][r][c][i];
                    if (legal(pr, pc)) cross[i] -= val_pref[dir][pr][pc][i];
                }
            } else {
                int rad = rad_x[r][c];
                int pr = r + rad * dr[dir], pc = c + rad * dc[dir];
                for (int i = 0; i < 4; i++) {
                    x[i] += val_pref[dir][r][c][i];
                    if (legal(pr, pc)) x[i] -= val_pref[dir][pr][pc][i];
                }
            }
        }
        if (rad_cross[r][c] > 0 && bigger(cross, ans)) ans = cross;
        if (rad_x[r][c] > 0 && bigger(x, ans)) ans = x;
    }
    cout << calc(ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}




