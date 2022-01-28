// by redleaf23477
// IDA*
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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

using Mat = array<int, 16>;

Mat puz;

void init() {
    for (int i = 0; i < 16; i++) cin >> puz[i];
}

int h(Mat &mat) {
    int sum = 0;
    for (int i = 0; i < 16; i++) {
        if (mat[i] == i+1 || mat[i] == 0) continue;
        int dr = abs(i/4 - (mat[i]-1)/4);
        int dc = abs(i%4 - (mat[i]-1)%4);
        sum += dr + dc;
    }
    return sum;
}

int dh(int prv_pos, int new_pos, int val) {
    val--;
    int prv_dr = abs(prv_pos/4 - val/4);
    int prv_dc = abs(prv_pos%4 - val%4);
    int new_dr = abs(new_pos/4 - val/4);
    int new_dc = abs(new_pos%4 - val%4);
    return new_dr + new_dc - prv_dr - prv_dc;
}

vector<char> dir {'U', 'D', 'L', 'R'};
vector<int> ans(100);
bool dfs(int dep, int heru, int zero, const int depLim) {
    if (dep+heru > depLim) return false;
    if (heru == 0) {
        ans.resize(dep);
        return true;
    }
    /*
    cerr << "puz = " << var(heru) << endl;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cerr << setw(2) << puz[r*4+c] << " ";
        }
        cerr << endl;
    }
    */

    // u, d, l, r
    vector<bool> cond {zero/4 > 0, zero/4 < 3, zero%4 > 0, zero%4 < 3};
    vector<int> nxt_z {zero-4, zero+4, zero-1, zero+1};

    for (int i = 0; i < 4; i++) {
        if (!cond[i]) continue;
        if (dep > 0 && i/2 == ans[dep-1]/2 && abs(i-ans[dep-1]) == 1) continue;  // inverse dir
        int dheru = dh(nxt_z[i], zero, puz[nxt_z[i]]);
        swap(puz[zero], puz[nxt_z[i]]);
        ans[dep] = i;
        if (dfs(dep+1, heru+dheru, nxt_z[i], depLim)) {
            return true;
        }
        swap(puz[zero], puz[nxt_z[i]]);
    }

    return false;
}

bool ida_star() {
    int hpuz = h(puz), zero = find(range(puz), 0)-puz.begin();
    for (int depLim = hpuz; depLim <= 45; depLim += 2) {
        if (dfs(0, hpuz, zero, depLim)) {
            /*
            for (auto i : ans) cout << dir[i];
            cout << endl;
            */
            cout << ans.size() << endl;
            return true;
        }
    }
    return false;
}

void process() {
    function<bool()> unsolvable = [&]() {
        int inv = 0, zero = find(range(puz), 0)-puz.begin();
        for (int i = 0; i < 16; i++) {
            if (puz[i] == 0) continue;
            for (int j = i+1; j < 16; j++) {
                if (puz[j] == 0) continue;
                if (puz[i] > puz[j]) inv++;
            }
        }
        return (inv%2 == zero/4%2);
    };
    if (unsolvable()) {
        cout << "This puzzle is not solvable." << endl; return;
    } else if (!ida_star()) {
        cout << "This puzzle is not solvable." << endl; return;
    }
}

