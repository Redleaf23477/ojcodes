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
    LL a, b, c; cin >> a >> b >> c;
    LL low = 1, high = min({a, b, c}), mid, ans = -1;
    while (low <= high) {
        mid = (low+high)/2;
        // bullet = 6*mid
        LL s = a+b+c - 3*mid;
        if (6*mid > s) {
            high = mid-1;
        } else if (s - 6*mid != 0) {
            low = mid+1;
        } else {
            ans = 1; break;
        }
    }
    if (ans == -1) cout << "No" << endl;
    else cout << "Yes" << endl;
}

