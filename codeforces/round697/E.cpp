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
    init();
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

LL c[1010][1010];

void init() {
    constexpr LL MOD = 1e9+7;
    c[0][0] = 1;
    for (int n = 1; n <= 1000; n++) {
        c[n][0] = c[n][n] = 1;
        for (int k = 1; k < n; k++) {
            c[n][k] = (c[n-1][k-1] + c[n-1][k]) % MOD;
        }
    }
    /*
    for (int n = 0; n <= 10; n++) {
        for (int k = 0; k <= n; k++) cerr << c[n][k] << " ";
        cerr << endl;
    }
    */
}

void process() {
    LL n, k; cin >> n >> k;
    map<LL,LL> mp; {
        for (int i = 0; i < n; i++) {
            LL x; cin >> x;
            if (mp.count(x) == 0) mp[x] = 0;
            mp[x]++;
        }
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (k >= it->second) k -= it->second;
        else {
            cout << c[it->second][k] << endl; return;
        }
    }
    cout << 1 << endl;
}

