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

LL n, k;
vector<LL> h;

void init() {
    cin >> n >> k;
    h.assign(n, 0); for (auto &x : h) cin >> x;
}

void process() {
    // [l, r]
    vector<tuple<LL,LL>> low(n); {
        for (int i = 0; i < n; i++) {
            low[i] = make_tuple(h[i], h[i]+k-1);
        }
    }
    auto intersect = [](LL l1, LL r1, LL l2, LL r2) {
        LL l = max(l1, l2), r = min(r1, r2);
        return r-l >= 0;
    };
    LL L = h[0], R = h[0]+k; bool ans = true;
    for (int i = 1; i < n-1; i++) {
        auto [l, r] = low[i];
        // can stand
        if (!intersect(L-k+1, R-1, l, r)) {
            ans = false; break;
        }
        // update L, R
        l = max(L-k+1, l), r = min(R-1, r);
        L = max(h[i], l), R = r+k;
    }
    if (L-k+1 <= h[n-1] && h[n-1] <= R-1 && ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

