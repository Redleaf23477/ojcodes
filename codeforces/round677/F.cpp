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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int R, C, k;
vector<vector<LL>> arr;

void init() {
    cin >> R >> C >> k;
    arr.assign(R, vector<LL>(C+1, 0));
    for (int r = 0; r < R; r++)
        for (int c = 1; c <= C; c++)
            cin >> arr[r][c];
}

void process() {
    // dp[row][prefix][pick][mod]
    const LL INF = 1ll << 60;
    using Row = vector<vector<vector<LL>>>;
    vector<Row> dp(R, Row(C+1, vector<vector<LL>>(C/2+1, vector<LL>(k, -INF))));

    auto dp_by_row = [](Row &dp, vector<LL> &arr) {
        dp[0][0][0] = 0;
        for (int i = 1; i <= C; i++) {
            dp[i][0][0] = 0;
            for (int j = 1; j <= C/2; j++) {
                for (int s = 0; s < k; s++) {
                    LL cand = dp[i-1][j][s];
                    if (cand >= 0) dp[i][j][s] = max(dp[i][j][s], cand);
                    cand = dp[i-1][j-1][(s-arr[i]%k+k)%k];
                    if (cand >= 0) dp[i][j][s] = max(dp[i][j][s], cand+arr[i]);
                }
            }
        }
    };

    for (int i = 0; i < R; i++) dp_by_row(dp[i], arr[i]);

    auto getRow = [](Row &dp) {
        vector<LL> mx(k, -INF);
        for (int i = 0; i <= C/2; i++)
            for (int s = 0; s < k; s++) {
                mx[s] = max(mx[s], dp[C][i][s]);
            }
        return mx;
    };

    vector<vector<LL>> dp2(R, vector<LL>(k, -INF));
    
    dp2[0] = getRow(dp[0]);

    /*
    cerr << "row[0] = ";
    for (auto x : dp2[0]) cerr << x << " ";
    cerr << endl;
    */

    for (int i = 1; i < R; i++) {
        vector<LL> mx = getRow(dp[i]);

        /*
        cerr << "row[" << i << "] = ";
        for (auto x : mx) cerr << x << " ";
        cerr << endl;
        */

        for (int s1 = 0; s1 < k; s1++)
            for (int s2 = 0; s2 < k; s2++) {
                int s = (s1+s2)%k;
                if (dp2[i-1][s1] >= 0 && mx[s2] >= 0)
                    dp2[i][s] = max(dp2[i][s], dp2[i-1][s1]+mx[s2]);
            }
    }

    cout << dp2[R-1][0] << endl;
}

