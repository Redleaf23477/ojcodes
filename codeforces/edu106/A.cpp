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
    int n, k1, k2, w, b; cin >> n >> k1 >> k2 >> w >> b;
    function<int(int,int)> cnt = [](int k1, int k2) {
        if (k1 > k2) swap(k1, k2);
        if (k1 == 0) {
            return k2/2;
        } else {
            return max(1 + (k1-1)/2 + (k2-1)/2, k1/2 + k2/2);
        }
    };
    int W = cnt(k1, k2), B = cnt(n-k1, n-k2);
    cout << (W >= w && B >= b? "YES" : "NO") << endl;
}

