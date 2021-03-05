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

int n;
vector<int> arr;

void init() {
    cin >> n; arr.assign(n, 0);
    for (auto &x : arr) cin >> x;
}

void process() {
    map<int,int> cnt; {
        for (auto x : arr) {
            if (cnt.count(x) == 0) cnt[x] = 0;
            cnt[x]++;
        }
    }
    map<int,int> occ; {
        for (auto [_, c] : cnt) {
            if (occ.count(c) == 0) occ[c] = 0;
            occ[c] ++;
        }
        /*
        cerr << "occ = ";
        for (auto [x,y]:occ) cerr << "(" << x << "," << y << ")";
        cerr << endl;
        */
    }
    int ans = n;
    int tooSmall = n, prv = 0, prv_c = 0, tooBig = 0;
    for (auto it = occ.rbegin(); it != occ.rend(); it++) {
        auto [c, num] = *it;
        tooSmall -= c*num;
        ans = min(ans, tooSmall + tooBig + prv * (prv_c-c));
        tooBig += prv * (prv_c-c);
        prv_c = c, prv += num;
    }
    cout << ans << endl;
}

