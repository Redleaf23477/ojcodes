// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;


void solve() {
    // input
    int R, C; cin >> C >> R;
    vector<vector<int>> arr(R, vector<int>(C));
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        cin >> arr[r][c];
    }

    // u, d, l, r and boundary check
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    function<bool(int,int)> valid = [&](int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    };

    // group by bfs
    vector<vector<int>> group(R, vector<int>(C, -1));
    vector<int> groupSize, groupHeight;
    function<int(int,int,int)> bfs = [&](int r, int c, int idx) {
        queue<pair<int,int>> q;
        q.emplace(r, c), group[r][c] = idx;
        int sz = 1;
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r+dr[d], nc = c+dc[d];
                if (valid(nr, nc)) {
                    if (arr[nr][nc] == arr[r][c] && group[nr][nc] == -1) {
                        sz++;
                        group[nr][nc] = idx;
                        q.emplace(nr, nc);
                    }
                }
            }
        }
        return sz;
    };
    int idx = 0;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (group[r][c] == -1) {
            int sz = bfs(r, c, idx);
            groupSize.emplace_back(sz);
            groupHeight.emplace_back(arr[r][c]);
            idx++;
        }
    }

    // calculate boarders of a group
    vector<int> boarder(idx, 878787);
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        int g = group[r][c];
        for (int d = 0; d < 4; d++) {
            int nr = r+dr[d], nc = c+dc[d];
            if (valid(nr, nc) && arr[nr][nc] != arr[r][c]) {
                boarder[g] = min(boarder[g], arr[nr][nc]);
            }
        }
    }

    /*
    cerr << "debug: " << endl;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cerr << group[r][c] << " ";
        }
        cerr << endl;
    }
    for (int i = 0; i < idx; i++) {
        cerr << "group " << i << ": ";
        cerr << "height = " << groupHeight[i] << "; ";
        cerr << "size = " << groupSize[i] << "; ";
        cerr << endl;
    }
    */

    // calculate answer
    int ans = 0;
    for (int i = 0; i < idx; i++) {
        if (boarder[i] > groupHeight[i]) {
            ans += groupSize[i];
        }
    }
    cout << ans << endl;
    
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    cout.flush();
    return 0;
}

