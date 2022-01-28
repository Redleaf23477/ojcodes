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
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init() {
}

void process() {
    int n, c; cin >> n >> c;
    if (c < n-1) {
        cout << "IMPOSSIBLE" << endl; return;
    }
    c -= n-1;
    vector<int> rev(n, -1);
    for (int i = 0; i < n && c > 0; i++) {
        rev[i] = min(c, n-1-i);
        c -= rev[i];
    }
    if (c > 0) {
        cout << "IMPOSSIBLE" << endl; return;
    }
    vector<int> arr(n); iota(range(arr), 1);
    for (int i = n-1; i >= 0; i--) {
        reverse(arr.begin()+i, arr.begin()+i+rev[i]+1);
    }
    cout << arr[0];
    for (int i = 1; i < n; i++) cout << " " << arr[i];
    cout << endl;
}

