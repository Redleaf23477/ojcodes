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
    vector<LL> arr(n); for (auto &x : arr) cin >> x;
    auto good = [&](LL test) -> LL {
        LL sum = test;
        for (int i = 1; i < n; i++) {
            LL lhs = 100*arr[i];
            LL rhs = sum*k;
            if (lhs <= rhs) {
                sum += arr[i];
            } else {
                return -1;
            }
        }
        return test - arr[0];
    };
    LL low = arr[0], high = (LL)1e15, mid, ans = -1;
    while (low <= high) {
        mid = (low + high)/2;
        LL res = good(mid);
        if (res != -1) ans = res, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}

