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

void init() {
}

void process() {
    LL n, k; cin >> n >> k;
    vector<LL> h(n); for (auto &x : h) cin >> x;
    LL ans = 0; 
    for (LL i = 0; i < k && ans != -1; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n-1) { ans = -1; break; }
            if (h[j] < h[j+1]) { ans = j, h[j]++; break; }
        }
    }
    if (ans == -1) cout << -1 << endl;
    else cout << ans+1 << endl;
}

