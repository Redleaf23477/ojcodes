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
    int n; cin >> n;
    vector<LL> x(n), y(n); {
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        sort(range(x)), sort(range(y));
    }
    if (n%2 != 0) cout << 1 << endl;
    else {
        LL nx = (x[n/2]-x[n/2-1]+1);
        LL ny = (y[n/2]-y[n/2-1]+1);
        cout << nx * ny << endl;
    }
}

