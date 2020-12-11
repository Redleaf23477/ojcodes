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

using P = tuple<int,int>;

int n;
vector<P> arr[10];

void init() {
    cin >> n;
    for (int i = 0; i < 10; i++) arr[i].clear();
    vector<vector<int>> mp(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        char ch; cin >> ch;
        mp[i][j] = ch-'0';
    }
    for (int r = 0; r < n; r++) {
        vector<bool> found(10, false);
        for (int c = 0; c < n; c++) {
            int d = mp[r][c];
            if (found[d] == false) {
                found[d] = true;
                arr[d].emplace_back(r, c);
            }
        }
        found.assign(10, false);
        for (int c = n-1; c >= 0; c--) {
            int d = mp[r][c];
            if (found[d] == false) {
                found[d] = true;
                arr[d].emplace_back(r, c);
            }
        }
    }
    for (int c = 0; c < n; c++) {
        vector<bool> found(10, false);
        for (int r = 0; r < n; r++) {
            int d = mp[r][c];
            if (found[d] == false) {
                found[d] = true;
                arr[d].emplace_back(r, c);
            }
        }
        found.assign(10, false);
        for (int r = n-1; r >= 0; r--) {
            int d = mp[r][c];
            if (found[d] == false) {
                found[d] = true;
                arr[d].emplace_back(r, c);
            }
        }
    }
}

void process() {
    auto tri = [] (P p1, P p2, P p3) {
        auto [r1, c1] = p1; auto [r2, c2] = p2; auto [r3, c3] = p3;
        LL v1r = r1 - r2, v1c = c1 - c2;
        LL v2r = r1 - r3, v2c = c1 - c3;
        return abs(v1r*v2c - v1c*v2r);
    };
    auto run = [&](int d) -> LL {
        int m = arr[d].size();
        if (m <= 1) return 0;
        LL ans = 0;
        for (int i = 0; i < m; i++) for (int j = i+1; j < m; j++) {
            auto [r1, c1] = arr[d][i];
            auto [r2, c2] = arr[d][j];
            if (r1 == r2) {
                LL d1 = r1 - 1, d2 = n-1 - r1;
                LL d = abs(c1 - c2);
                ans = max({ ans, d1*d, d2*d });
            } else if (c1 == c2) {
                LL d1 = c1 - 1, d2 = n-1 - c1;
                LL d = abs(r1 - r2);
                ans = max({ ans, d1*d, d2*d });
            } else {
                LL r[] = {0, n-1, r1, r1, 0, n-1, r2, r2};
                LL c[] = {c1, c1, 0, n-1, c2, c2, 0, n-1};
                for (int p = 0; p < 8; p++) {
                    ans = max(ans, tri(P(r[p], c[p]), arr[d][i], arr[d][j]));
                }
            }
        }
        return ans;
    };
    for (int d = 0; d < 10; d++) { 
        cout << run(d) << " ";
    }
    cout << endl;
}

