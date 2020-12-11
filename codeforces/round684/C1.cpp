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

int R, C;
char arr[102][102];

void init() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) 
            cin >> arr[i][j];
}

void process() {
    vector<tuple<tuple<int,int>,tuple<int,int>,tuple<int,int>>> ans;
    for (int r = 0; r+1 < R; r++) for (int c = 0; c+1 < C; c++) {
        vector<tuple<int,int>> z, o;
        for (int dr = 0; dr < 2; dr++) for (int dc = 0; dc < 2; dc++) {
            int a = r+dr, b = c+dc;
            if (arr[a][b] == '0') z.emplace_back(a, b);
            else o.emplace_back(a, b);
            arr[a][b] = '0';
        }
        if (z.size() == 4) continue;
        else if (z.size() == 3) {
            auto a = z[0], b = z[1], c = z[2];
            auto d = o[0];
            ans.emplace_back(a, b, d);
            ans.emplace_back(b, c, d);
            ans.emplace_back(a, c, d);
        } else if (z.size() == 2) {
            auto a = z[0], b = z[1];
            auto c = o[0], d = o[1];
            ans.emplace_back(a, b, c);
            ans.emplace_back(a, b, d);
        } else if (z.size() == 1) {
            ans.emplace_back(o[0], o[1], o[2]);
        } else {
            auto a = o[0], b = o[1], c = o[2], d = o[3];
            ans.emplace_back(a, b, c);
            ans.emplace_back(a, b, d);
            ans.emplace_back(b, c, d);
            ans.emplace_back(a, c, d);
        }
    }
    cout << ans.size() << endl;
    for (auto [t1, t2, t3] : ans) {
        cout << get<0>(t1)+1 << " " << get<1>(t1)+1 << " ";
        cout << get<0>(t2)+1 << " " << get<1>(t2)+1 << " ";
        cout << get<0>(t3)+1 << " " << get<1>(t3)+1 << endl;
    }
}

