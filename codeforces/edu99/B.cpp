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
        process();
    }
    cout.flush();
    return 0;
}

void init() {
}

void process() {
    LL x; cin >> x;
    LL low = 1, high = 1000000, mid, ans = -1;
    while (low <= high) {
        mid = (low + high)/2;
        LL len = (1+mid)*mid/2;
        if (len > x+1) ans = mid, high = mid-1;
        else low = mid+1;
    }
    LL t = sqrt(1+8*x);
    if (t*t == 1+8*x && t % 2 == 1) ans = (-1 + t)/2;
    cout << ans << endl;
}

