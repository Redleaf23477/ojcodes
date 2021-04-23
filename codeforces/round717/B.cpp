// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// variadic print template, requires c++17
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
    int n; cin >> n;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    int s = 0; for (auto x : arr) s ^= x;
    if (s == 0) { cout << "YES" << endl; return; }
    int t = 0, cnt = 0;
    for (auto x : arr) {
        t ^= x;
        if (t == s) t = 0, cnt++;
    }
    if (t == 0 && cnt > 1) { cout << "YES" << endl; return; }
    cout << "NO" << endl;
}

