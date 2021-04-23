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
    int T = 1;
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
    int n, q; cin >> n >> q;
    LL k; cin >> k;
    vector<LL> arr(n); for (auto &x : arr) cin >> x;
    vector<LL> rg(n); {
        for (int i = 0; i < n; i++) {
            LL mn = 1, mx = k;
            if (i-1 >= 0) mn = max(mn, arr[i-1]+1);
            if (i+1 < n) mx = min(mx, arr[i+1]-1);
            rg[i] = mx-mn;
        }
        for (int i = 1; i < n; i++) rg[i] += rg[i-1];
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        if (l == r) { cout << k-1 << endl; continue; }
        LL ans = arr[l+1]-1-1 + k-arr[r-1]-1 + rg[r-1] - rg[l];
        cout << ans << endl;
    }
}

