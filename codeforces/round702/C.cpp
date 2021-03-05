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
    init();
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

vector<LL> cube;

void init() {
    cube.assign(1000006, -7122);
    for (LL i = 1; i < 1000006; i++) cube[i] = i*i*i;
}

void process() {
    LL x; cin >> x;
    for (auto c : cube) {
        if (x < c) break;
        if (binary_search(range(cube), x-c)) {
            cout << "YES" << endl; return;
        }
    }
    cout << "NO" << endl;
}

