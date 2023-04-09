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
    vector<Vec3D> vec_normal(6);
    Solver(int _n): n(_n), arr(6, make_nxn_grid(n)) {
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
        vec_normal[DOWN] = Vec3D(0, 0, -1);
    }

    bool in_range(int x, int y, int z) {
        return 0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n; 
    }
    int get_index(int x, int y, int z) { 
        return x * n * n + y * n + z; 
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
            return arr[aspect][n-1-y][x];
        }
    }
    void solve() {
        int ans = n * n * n;
        vector<int> expose(n * n * n, 0);
        // TODO: initialize expose
        {
        }
        // iteratively push points that is exposed on three axis into Q
        vector<bool> vis(n * n * n, false);
        queue<Point> Q;
        for (auto x : {0, n-1}) for (auto y : {0, n-1}) for (auto z : {0, n-1}) {
            vis[get_index(x, y, z)] = true;
            Q.emplace(x, y, z);
        }
        while (!Q.empty()) {
            auto [x, y, z] = Q.front(); Q.pop();
            int idx = get_index(x, y, z);
            if (good(x, y, z, expose[idx])) {
                unmark_constraint(x, y, z, exposed[idx]);
            } else {
                ans--;
            }
            remove_and_push(x, y, z, Q, vis);
        }
        // print answer
        cout << "Maximum weight: " << ans << " gram(s)\n";
    }
    bool good(int x, int y, int z, int expose) {
        char color = '*';
        for (int aspect = 0; aspect < 6; aspect++) {
            if ((expose >> aspect) & 1) {
                char &ch = get_constraint(x, y, z, aspect);
                if (ch == '.') {
                    return false;
                } else if (ch == '*') {
                    continue;
                } else if (ch != color) {
                    if (color == '*') {
                        color = ch;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void unmark_constraint(int x, int y, int z, int expose) {
        for (int aspect = 0; aspect < 6; aspect++) {
            if ((expose >> aspect) & 1) {
                char &ch = get_constraint(x, y, z, aspect);
                ch = '*';
            }
        }
    }
    bool valid_exposure(int expose) {
        // each of x, y, z must have at least one
        bool x_dir = ((expose >> RIGHT) & 1) && ((expose >> LEFT) & 1);
        bool y_dir = ((expose >> FRONT) & 1) && ((expose >> BACK) & 1);
        bool z_dir = ((expose >> TOP) & 1) && ((expose >> DOWN) & 1);
        return x_dir && y_dir && z_dir;
    }
    void remove_and_push(int x, int y, int z, queue<Point> &Q, vector<bool> &vis, vector<int> &expose) {
        int me_index = get_index(x, y, z);
        int me_expose = expose[me_index];
        for (int aspect = 0; aspect < 6; aspect++) {
            if ((me_expose >> aspect) & 1) {
                auto [dx, dy, dz] = vec_normal[aspect];
                int nx = x + dx, ny = y + dy, nz = z + dz;
                int child_idx = get_index(nx, ny, nz);
                if (in_range(nx, ny, nz)) {
                    expose[child_idx] |= (1 << aspect);
                    if (!vis[child_idx] && valid_exposure(expose[child_idx]) >= 3) {
                        vis[child_idx] = true;
                        Q.emplace(nx, ny, nz);
                    }
                }
            }
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



