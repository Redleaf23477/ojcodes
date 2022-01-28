// by redleaf23477
// A* will TLE
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

using Mat = array<int, 16>;
using Stat = tuple<int, int, Mat>;  // g+h, g, Mat

Mat puz;

void init() {
    for (int i = 0; i < 16; i++) cin >> puz[i];
}


void a_star() {
    map<Mat, Mat> back;
    priority_queue<Stat, vector<Stat>, greater<Stat>> pq;

    function<void(Mat&, int)> print = [&](Mat &mat, int dist) {
        int zero = find(range(mat), 0) - mat.begin();
        string stk(dist, 'X');
        for (int d = 0; d < dist; d++) {
            Mat &prv = back[mat];
            int prv_zero = find(range(prv), 0)-prv.begin();
            if (prv_zero+1 == zero) stk[d] = 'R';
            else if (prv_zero-1 == zero) stk[d] = 'L';
            else if (prv_zero+4 == zero) stk[d] = 'D';
            else stk[d] = 'U';
            mat = prv;
            zero = prv_zero;
        }
        reverse(range(stk));
        cout << stk << endl;
    };
    function<int(Mat&)> h = [](Mat &mat) {
        int sum = 0;
        for (int i = 0; i < 16; i++) {
            if (mat[i] == i+1 || mat[i] == 0) continue;
            int dr = abs(i/4 - (mat[i]-1)/4);
            int dc = abs(i%4 - (mat[i]-1)%4);
            sum += dr + dc;
        }
        /*
        cerr << "h:" << var(sum) << endl;
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cerr << mat[r*4+c] << " ";
            }
            cerr << endl;
        }
        */
        return sum;
    };
    function<bool(Mat&)> solved = [](Mat &mat) {
        bool res = true;
        for (int i = 0; i < 15; i++) {
            if (mat[i] != i+1) res = false;
        }
        /*
        cerr << "solved: ";
        for (auto x : mat) cerr << x << " ";
        cerr << var(res) << endl;
        */
        return res;
    };
    function<void(int,int,int)> nxt_step = [&](int zero, int swp, int dist) {
        static Mat nxt;
        nxt = puz;
        swap(nxt[zero], nxt[swp]);
        if (back.count(nxt) == 0) {
            back[nxt] = puz;
            pq.emplace(dist+1+h(nxt), dist+1, nxt);
        }
    };

    pq.emplace(0+h(puz), 0, puz);
    while (!pq.empty()) {
        auto f = pq.top(); pq.pop();
        int hg = get<0>(f), dist = get<1>(f);
        puz = get<2>(f);
        if (solved(puz)) {
            print(puz, dist);
            return;
        }
        if (dist == 50) {
            return;
        }
        int zero = find(range(puz), 0) - puz.begin();
        if (zero/4 > 0) {
            int swp = zero-4;
            nxt_step(zero, swp, dist);
        }
        if (zero/4 < 3) {
            int swp = zero+4;
            nxt_step(zero, swp, dist);
        }
        if (zero%4 > 0) {
            int swp = zero-1;
            nxt_step(zero, swp, dist);
        }
        if (zero%4 < 3) {
            int swp = zero+1;
            nxt_step(zero, swp, dist);
        }
    }
}

void process() {
    function<bool()> unsolvable = [&]() {
        int inv = 0, zero = find(range(puz), 0)-puz.begin();
        for (int i = 0; i < 16; i++) {
            for (int j = i+1; j < 16; j++) {
                if (puz[i] > puz[j]) inv++;
            }
        }
        return (zero/4 % 2) != (inv % 2);
    };
    if (unsolvable()) {
        cout << "This puzzle is not solvable." << endl; return;
    } else {
        a_star();
    }
}

