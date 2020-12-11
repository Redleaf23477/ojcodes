// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
//#define endl '\n'
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

int R, C;
vector<vector<char>> arr;
vector<vector<int>> len;

void init() {
    cin >> R >> C;
    arr.assign(R, vector<char>(C));
    len.assign(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
        cin >> arr[i][j];
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        for (int l = 1; j-l+1 >= 0 && j+l-1 < C; l++) {
            if (arr[i][j-l+1] == '*' && arr[i][j+l-1] == '*') len[i][j] = l;
            else break;
        }
    }
    /*
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++)
            cerr << len[r][c] << " ";
        cerr << endl;
    }
    */
}

void process() {
    LL ans = 0;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        for (int d = 1; r+d-1 < R; d++) {
            if (len[r+d-1][c] >= d) ans++;
            else break;
        }
    }
    cout << ans << endl;
}

