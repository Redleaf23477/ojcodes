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
    vector<bool> good {1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
    vector<int> mirror {0, 1, 5, 0, 0, 2, 0, 0, 8, 0};
    int H, M; cin >> H >> M;
    function<bool(int,int)> ok = [&](int h, int m) {
        for (auto x : {h%10, h/10, m%10, m/10}) {
            if (!good[x]) return false;
        }
        int m2 = mirror[h%10]*10 + mirror[h/10];
        int h2 = mirror[m%10]*10 + mirror[m/10];
        return h2 < H && m2 < M;
    };
    function<void(int&,int&)> adv = [&](int &h, int &m) {
        m++;
        if (m >= M) h++, m = 0;
        if (h >= H) h = 0;
    };
    char ch;
    int h, m; cin >> h >> ch >> m;
    while (!ok(h, m)) {
        adv(h, m);
    }
    cout << setw(2) << setfill('0') << h;
    cout << ":";
    cout << setw(2) << setfill('0') << m;
    cout << endl;
}

