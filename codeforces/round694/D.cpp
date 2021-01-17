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
    init();
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

vector<LL> sp;

void init() {
    const LL N = 1000006;
    sp.assign(N, 0);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i*i < N; i++) {
        if (sp[i] != i) continue;
        for (LL j = i*i; j < N; j += i) {
            sp[j] = i;
        }
    }
}

void process() {
    int n; cin >> n;
    map<LL, LL> mp; {
        for (int i = 0; i < n; i++) {
            LL x, s = 1; cin >> x;
            while (x != 1) {
                LL p = sp[x];
                if (s % p == 0) s /= p;
                else s *= p;
                x /= p;
            }
            if (mp.count(s) == 0) mp[s] = 0;
            mp[s]++;
        }
    }
    LL initAns = 0, afterAns = 0;
    // time = 0
    for (auto [s, cnt] : mp) {
        initAns = max(initAns, cnt);
    }
    // time = 1
    if (mp.count(1) != 0) afterAns = mp[1];
    for (auto [s, cnt] : mp) {
        if (s == 1) continue;
        if (cnt % 2 == 0) afterAns += cnt;
    }
    afterAns = max(afterAns, initAns);
    int q; cin >> q;
    while (q--) {
        LL w; cin >> w;
        if (w == 0) cout << initAns << endl;
        else cout << afterAns << endl;
    }
}

