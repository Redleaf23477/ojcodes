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

int n;
vector<LL> arr;
vector<LL> bitwise;

void init() {
    cin >> n;
    arr.resize(n); for (auto &x:arr) cin >> x;
    bitwise.assign(63, 0);
}

void process() {
    // calculate sum of each bit
    for (auto x : arr) {
        for (int b = 0; b < 63; b++) {
            bitwise[b] += (x>>b)&1;
        }
    }
    /*
     * sum(i) sum(j) sum(k) (xi & xj)*(xj | xk)
     * = sum(i) sum(j) (xi & xj) * sum(k) (xj | xk)
     * = sum(j) sum(i) (xj & xi) * sum(k) (xj | xk)
     * = sum(j) { sum(i) (xj & xi) } * { sum(k) (xj | xk) }
     */
    LL ans = 0;
    const LL MOD = 1e9+7;
    auto add = [](LL lhs, LL rhs) {
        return (lhs + rhs)%MOD;
    };
    for (auto xj : arr) {
        LL s_and = 0, s_or = xj%MOD*n%MOD;
        for (int b = 0; b < 63; b++) {
            // and
            if ((xj >> b)&1) {
                s_and = add(s_and, (1ll<<b)%MOD*bitwise[b]%MOD);
            }
            // or
            if (((xj >> b)&1) == 0) {
                s_or = add(s_or, (1ll<<b)%MOD*bitwise[b]%MOD);
            }
        }
        ans = add(ans, s_and*s_or%MOD);
    }
    cout << ans << endl;
}

