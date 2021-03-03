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

int n, U, R, D, L;

void init() {
    cin >> n >> U >> R >> D >> L;
}

bool good(int i) {
    /*
     * a ... b
     * ...
     * c ... d
     */
    bool a = ((i>>0)&1);
    bool b = ((i>>1)&1);
    bool c = ((i>>2)&1);
    bool d = ((i>>3)&1);

    if (U < a+b || U > a+b+(n-2)) return false;
    if (R < b+d || R > b+d+(n-2)) return false;
    if (D < c+d || D > c+d+(n-2)) return false;
    if (L < a+c || L > a+c+(n-2)) return false;
    return true;
}

void process() {
    for (int i = 0; i < 16; i++) {
        if (good(i)) {
            cout << "YES" << endl; return;
        }
    }
    cout << "NO" << endl;
}

