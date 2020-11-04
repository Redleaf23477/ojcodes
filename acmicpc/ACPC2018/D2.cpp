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
using PLL = pair<LL,LL>;
#define r first
#define c second

ifstream fin ("dull.in");
#define cin fin

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

const int N = 2003;

vector<LL> R, C;
LL cnt[N][N];
LL dp[N][N][2];

void uniq(vector<LL> &arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
}

void init() {
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));

    LL r, c, k; cin >> r >> c >> k;
    R = (vector<LL>){r}, C = (vector<LL>){c};
    vector<PLL> pts(k);
    for (auto &p : pts) {
        cin >> p.r >> p.c;
        R.emplace_back(p.r);
        C.emplace_back(p.c);
        if(p.r > 1) R.emplace_back(p.r-1);
        if(p.c > 1) C.emplace_back(p.c-1);
    }
    
    uniq(R), uniq(C);
    vector<int> num(max(R.size(), C.size()));
    iota(num.begin(), num.end(), 0);

    auto find = [num](LL x, vector<LL> &arr) {
        auto it = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        return num[it];
    };

    for (auto p : pts) {
        int r = find(p.r, R), c = find(p.c, C);
        cnt[r][c]++;
    }
}

void process() {
    int N = R.size(), M = C.size();

    /*
    cerr << "R = ";
    for (auto r : R) cerr << r << " ";
    cerr << endl;
    cerr << "C = ";
    for (auto c : C) cerr << c << " ";
    cerr << endl;
    */
    
    // prefix on cnt
    for (int r = 0; r < N; r++)
        for (int c = 1; c < M; c++)
            cnt[r][c] += cnt[r][c-1];
    for (int r = 1; r < N; r++)
        for (int c = 0; c < M; c++)
            cnt[r][c] += cnt[r-1][c];

    /*
    cerr << "cnt = " << endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cerr << cnt[r][c] << " ";
        }
        cerr << endl;
    }
    */

    // dp
    // base case
    dp[0][0][0] = R[0]*C[0]*(cnt[0][0] % 2 == 0), dp[0][0][1] = R[0]*C[0]*(cnt[0][0] % 2 == 1);
    for (int r = 1; r < N; r++) {
        LL dr = R[r] - R[r-1], add = (cnt[r][0] - cnt[r-1][0]) % 2;
        for (int k = 0; k < 2; k++) {
            dp[r][0][k] += dr * dp[r-1][0][k ^ add];
        }
    }
    for (int c = 1; c < N; c++) {
        LL dc = C[c] - C[c-1], add = (cnt[0][c] - cnt[0][c-1]) % 2;
        for (int k = 0; k < 2; k++) {
            dp[0][c][k] += dc * dp[0][c-1][k ^ add];
        }
    }
    // dp case
    for (int r = 1; r < N; r++) {
        LL dr = R[r] - R[r-1];
        for (int c = 1; c < M; c++) {
            LL add = (cnt[r][c] - cnt[r-1][c]) % 2;
            for (int k = 0; k < 2; k++) {
                dp[r][c][k] += dr * dp[r-1][c][k ^ add];
            }
        }
    }

    /*
    for (int k = 0; k < 2; k++) {
        cerr << "dp[r][c][" << k << "] = " << endl;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                cerr << dp[r][c][k] << " ";
            }
            cerr << endl;
        }
    }
    */

    // ans
    LL ans[2] = {0};
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            for (int k = 0; k < 2; k++)
                ans[k] += dp[r][c][k];
        }
    }
    cout << ans[1] << " " << ans[0] << endl;
}

