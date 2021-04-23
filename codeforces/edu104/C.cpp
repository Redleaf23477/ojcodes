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
    int win = n*(n-1)/2/n;
    if (n%2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1, w = 0; j < n; j++) {
                if (w < win) { cout << 1 << " "; w++; }
                else if (w == win) { cout << 0 << " "; w++; }
                else cout << -1 << " ";
            }
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i+1, w = 0; j < n; j++) {
                if (w < win) { cout << 1 << " "; w++; }
                else cout << -1 << " ";
            }
        }
        cout << endl;
    }
}

