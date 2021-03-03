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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int a, b, k;

void init() {
    cin >> b >> a >> k;
}

void process() {
#define GG do { cout << "No" << endl; return; } while (0)

    int n = a+b;
    if (a == 0) GG;
    if (k == 0) {
        cout << "Yes" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < a; j++) cout << '1';
            for (int j = 0; j < b; j++) cout << '0';
            cout << endl;
        }
        return;
    }
    if (a+b-2 < k) { GG; }
    // build the answer
    // Step: No trailing zeros
    string x(n, 'x'), y(n, 'x');
    x[0] = '1', y[0] = '1', a--;
    // Step: k 1s in x-y
    if (a == 0 || b == 0) GG;
    x[1] = '1', y[1] = '0';
    x[1+k] = '0', y[1+k] = '1'; 
    a--, b--;
    // Step: fill in 'x'
    for (int i = 2; i < n; i++) {
        if (x[i] != 'x') continue;
        if (a > 0) x[i] = '1', y[i] = '1', a--;
        else if (b > 0) x[i] = '0', y[i] = '0', b--;
        else GG;
    }

    cout << "Yes" << endl;
    cout << x << endl;
    cout << y << endl;
#undef GG
}

