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
    LL u, v; cin >> u >> v;
    auto lowbit = [](LL x) -> LL { return x & (-x); };
    if (u > v) { cout << "NO" << endl; return; }
    while (u && v) {
        LL lu = lowbit(u), lv = lowbit(v);
        if (lu > lv) { cout << "NO" << endl; return; }
        u -= lu, v -= lv;
    }
    if (v > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

