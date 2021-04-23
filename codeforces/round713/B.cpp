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

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init() {
}

void process() {
    int n; cin >> n;
    vector<pair<int,int>> p;
    vector<vector<char>> ans(n, vector<char>(n, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch; cin >> ch;
            if (ch == '*') p.emplace_back(i, j), ans[i][j] = '*';
        }
    }

    if (p[0].first == p[1].first) {
        int r = (p[0].first == 0? 1 : 0);
        ans[r][p[0].second] = '*';
        ans[r][p[1].second] = '*';
    } else if (p[0].second == p[1].second) {
        int c = (p[0].second== 0? 1 : 0);
        ans[p[0].first][c] = '*';
        ans[p[1].first][c] = '*';
    } else {
        ans[p[0].first][p[1].second] = '*';
        ans[p[1].first][p[0].second] = '*';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

