#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

/*
 *
 *       
 *                  ^                 +-------+
 *              +y /                 /  top  /|
 *                /                 /       / |
 *       (0,0,0) O-------->        +-------+  | right
 *               |   +x       left |       |  +
 *            +z |                 | front | /
 *               |                 |       |/
 *               v                 +-------+
 *                    
 *
 */

struct Solver {
    using Grid = vector<vector<char>>;
    Grid make_nxn_grid(int n) {
        return vector<vector<char>>(n, vector<char>(n));
    }
    using Point = tuple<int,int,int>;
    using Vec3D = tuple<int,int,int>;

    static constexpr int FRONT = 0, LEFT = 1, BACK = 2, RIGHT = 3, TOP = 4, BOTTOM = 5;

    int n;
    vector<Grid> arr;  // front, left, back, right, top, bottom
    vector<Vec3D> vec_normal;
    Solver(int _n): n(_n), arr(6, make_nxn_grid(n)), vec_normal(6) {
        for (int r = 0; r < n; r++) {
            for (int gid = 0; gid < 6; gid++) {
                for (int c = 0; c < n; c++) {
                    cin >> arr[gid][r][c];
                }
            }
        }
        vec_normal[FRONT] = Vec3D(0, +1, 0);
        vec_normal[LEFT] = Vec3D(+1, 0, 0);
        vec_normal[BACK] = Vec3D(0, -1, 0);
        vec_normal[RIGHT] = Vec3D(-1, 0, 0);
        vec_normal[TOP] = Vec3D(0, 0, +1);
        vec_normal[BOTTOM] = Vec3D(0, 0, -1);
    }

    bool in_range(int x, int y, int z) {
        return 0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n; 
    }
    int get_index(int x, int y, int z) { 
        return x * n * n + y * n + z; 
    }
    Point get_point(int idx) {
        return Point(idx / (n * n), idx % (n * n) / n, idx % n);
    }
    char& get_constraint(int x, int y, int z, int aspect) {
        assert(0 <= aspect && aspect < 6 && "bad aspect");
        if (aspect == 0) {
            // front
            return arr[aspect][z][x];
        } else if (aspect == 1) {
            // left 
            return arr[aspect][z][n-1-y];
        } else if (aspect == 2) {
            // back
            return arr[aspect][z][n-1-x];
        } else if (aspect == 3) {
            // right 
            return arr[aspect][z][y];
        } else if (aspect == 4) {
            // top
            return arr[aspect][n-1-y][x];
        } else {
            // down 
            return arr[aspect][y][x];
        }
    }
    Point translate_point(int aspect, int r, int c) {
        assert(0 <= aspect && aspect < 6 && "bad aspect");
        if (aspect == 0) {
            // front
            return Point(c, 0, r);
        } else if (aspect == 1) {
            // left 
            return Point(0, n-1-c, r);
        } else if (aspect == 2) {
            // back
            return Point(n-1-c, n-1, r);
        } else if (aspect == 3) {
            // right 
            return Point(n-1, c, r);
        } else if (aspect == 4) {
            // top
            return Point(c, n-1-r, 0);
        } else {
            // down 
            return Point(c, r, n-1);
        }
    }
    void solve() {
        vector<int> expose(n * n * n, 0);
        vector<bool> is_done(n * n * n, false);
        int penetrate_cnt = remove_penetrated(is_done);
        initialize_expose(expose, is_done);
        // iteratively check all cubes until 
        // all constraints hold or no cubes are deleted
        int ans = n * n * n - penetrate_cnt;
        while (true) {
            bool update = false;
            for (int cube = 0; cube < n * n * n; cube++) {
                if (is_done[cube]) continue;
                if (bad_cube(cube, expose[cube])) {
                    // 1) violates constraints
                    // debug(cube, expose[cube], "kill");
                    update_exposure(cube, expose, is_done);
                    is_done[cube] = update = true;
                    ans--;
                } else if (good_cube(cube, expose[cube])) {
                    // 2) fullfills all constraints
                    // debug(cube, expose[cube], "good");
                    unmark_constraints(cube, expose[cube]);
                    is_done[cube] = update = true;
                }
                // else: I don't know how to deal with the
                // cube yet. Leave it for further iter.
            }
            if (!update) break;
        }
        /*
        for (int i = 0; i < n * n * n; i++) {
            if (!is_done[i]) {
                auto [x, y, z] = get_point(i);
                cerr << "WTF: (" << x << "," << y << "," << z << "), expose = " << expose[i] << endl;
            }
        }
        */
        // print answer
        cout << "Maximum weight: " << ans << " gram(s)\n";
    }
    void debug(int cube, int expose, string msg) {
        auto [x, y, z] = get_point(cube);
        vector<string> verbose {
            "front", "left", "back", "right", "top", "bottom"
        };
        cerr << msg << " (" << x << "," << y << "," << z << "), expose to: ";
        for (int aspect = 0; aspect < 6; aspect++) if ((expose >> aspect) & 1) {
            cerr << verbose[aspect] << ", ";
        }
        cerr << endl;
    }
    int remove_penetrated(vector<bool> &is_done) {
        int bye = 0;
        for (int aspect = 0; aspect < 6; aspect++) {
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
                if (arr[aspect][i][j] == '.') {
                    auto [x, y, z] = translate_point(aspect, i, j);
                    auto [dx, dy, dz] = vec_normal[aspect];
                    for (int k = 0; k < n; k++) {
                        int idx = get_index(x, y, z);
                        if (!is_done[idx]) {
                            is_done[idx] = true;
                            bye++;
                        }
                        x += dx, y += dy, z += dz;
                    }
                }
            }
        }
        return bye;
    }
    void initialize_expose(vector<int> &expose, vector<bool> &is_done) {
        for (int aspect = 0; aspect < 6; aspect++) {
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
                if (arr[aspect][i][j] == '.') continue;
                auto [x, y, z] = translate_point(aspect, i, j);
                auto [dx, dy, dz] = vec_normal[aspect];
                for (int k = 0; k < n; k++) {
                    int idx = get_index(x, y, z);
                    if (!is_done[idx]) {
                        expose[idx] |= (1 << aspect);
                        break;
                    }
                    x += dx, y += dy, z += dz;
                }
            }
        }
    }
    bool bad_cube(int cube, int expose) {
        auto [x, y, z] = get_point(cube);
        // any two exposures conflicts
        char constraint = '*';
        for (int e1 = 0; e1 < 6; e1++) if ((expose >> e1) & 1) {
            char c = get_constraint(x, y, z, e1);
            if (c == '*') continue;
            else if (c == '.') return true;
            else {
                if (constraint == '*') constraint = c;
                else if (constraint != c) return true;
            }
        }
        return false;
    }
    void update_exposure(int cube, vector<int> &expose, vector<bool> &is_done) {
        auto [x, y, z] = get_point(cube);
        int me_expose = expose[cube];
        for (int aspect = 0; aspect < 6; aspect++) if ((me_expose >> aspect) & 1) {
            auto [dx, dy, dz] = vec_normal[aspect];
            int nx = x + dx, ny = y + dy, nz = z + dz;
            for (int k = 0; k < n; k++) {
                if (in_range(nx, ny, nz)) {
                    int nidx = get_index(nx, ny, nz);
                    if (!is_done[nidx]) {
                        expose[nidx] |= (1 << aspect);
                        break;
                    }
                } else {
                    break;
                }
                nx += dx, ny += dy, nz += dz;
            }
        }
    }
    bool good_cube(int cube, int expose) {
        auto [x, y, z] = get_point(cube);
        // three axis agrees with each other
        vector<char> axis;
        // x, y, z directions
        vector<tuple<int,int>> directions {
            {LEFT, RIGHT}, {FRONT, BACK}, {TOP, BOTTOM}
        };
        for (auto [side1, side2] : directions) {
            char c1 = get_constraint(x, y, z, side1);
            char c2 = get_constraint(x, y, z, side2);
            if (c1 == '.' || c2 == '.') return false;
            if (c1 == '*' && c2 == '*') continue;
            if (c1 != '*' && ((expose >> side1) & 1)) {
                axis.emplace_back(c1);
            } else if (c2 != '*' && ((expose >> side2) & 1)) {
                axis.emplace_back(c2);
            } else {
                return false;
            }
        }
        for (size_t i = 1; i < axis.size(); i++) {
            if (axis[i] != axis[0]) return false;
        }
        return true;
    }
    void unmark_constraints(int cube, int expose) {
        auto [x, y, z] = get_point(cube);
        for (int aspect = 0; aspect < 6; aspect++) if ((expose >> aspect) & 1) {
            get_constraint(x, y, z, aspect) = '*';
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while (cin >> n && n) {
        Solver(n).solve();
    }
}



