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

LL n, m, k;
vector<vector<LL>> arr;

void init() {
    cin >> n >> m >> k;
    arr.assign(n, vector<LL>(m+1, 0));
    for(int i = 0; i < n; i++) for(int j = 1; j <= m; j++) cin >> arr[i][j];
}

const int N = 75;

LL dp1[N][N][N][N]; // row, prefix, pick, sum;
LL dp2[N][N]; // prefix, sum

const LL INF = 1ll<< 60;

void process() {
    // dp1
    for(int r = 0; r < n; r++) {
        for(int i = 0; i <= m; i++) {
            for(int c = 0; c <= m/2; c++) {
                for(int s = 0; s < k; s++) {
                    dp1[r][i][c][s] = -INF;
                }
            }
            dp1[r][i][0][0] = 0;
        }
    }
    for(int r = 0; r < n; r++) {
        for(int i = 1; i <= m; i++) {
            for(int c = 1; c <= m/2; c++) {
                // skip i
                for(int s = 0; s < k; s++) {
                    dp1[r][i][c][s] = dp1[r][i-1][c][s];
                }
                // pick i
                for(int s = 0; s < k; s++) {
                    // pick i
                    dp1[r][i][c][(s+arr[r][i])%k] = max(dp1[r][i][c][(s+arr[r][i])%k], dp1[r][i-1][c-1][s] + arr[r][i]);
                }
            }
        }
    }
    /*
    cerr << "dp1[0] = " << endl;
    for(int i = 0; i <= m; i++) {
        for(int c = 0; c <= m/2; c++) {
            cerr << "{";
            for(int s = 0; s < k; s++) {
                cerr << (dp1[0][i][c][s] < 0? -1 : dp1[0][i][c][s]) << ",";
            }
            cerr << "}";
        }
        cerr << endl;
    }
    */
    /*
    cerr << "LALALALA" << endl;
    for(int r = 0; r < n; r++) {
        cerr << var(r) << " : ";
        for(int s = 0; s < k; s++) 
            cerr << dp1[r][m][m/2][s] << " ";
        cerr << endl;
    }
    */
    // dp2
    for(int s = 0; s < k; s++) dp2[0][s] = max(0ll, dp1[0][m][m/2][s]);
    for(int i = 1; i < n; i++) {
        for(int s0 = 0; s0 < k; s0++) for(int s1 = 0; s1 < k; s1++) {
            LL sum = (dp2[i-1][s0] + max(0ll, dp1[i][m][m/2][s1]));
            dp2[i][sum%k] = max(dp2[i][sum%k], sum);
        }
    }
    
    /*
    cerr << "dp2 = " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cerr << dp2[i][j] << " ";
        }
        cerr << endl;
    }
    */


    cout << dp2[n-1][0] << endl;

}
