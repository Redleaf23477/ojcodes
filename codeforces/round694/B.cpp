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
    int n; cin >> n;
    LL x; cin >> x;
    vector<LL> arr(n); for (auto &x : arr) cin >> x;
    vector<LL> cnt(n, 1);
    LL ans = 0; for (auto x : arr) ans += x;
    for (bool cont = true; cont; ) {
        for (int i = 0; i < n && cont; i++) {
            if (arr[i] % x == 0) {
                ans += cnt[i] * arr[i];
                arr[i] /= x;
                cnt[i] = cnt[i] * x;
            } else {
                cont = false;
            }
        }
    }
    cout << ans << endl;
}

