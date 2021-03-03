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
    int n; cin >> n;
    string b; cin >> b;
    string a(n, '0'), c(n, '0');
    a[0] = '1', c[0] = a[0]-'0'+b[0];
    for (int i = 1; i < n; i++) {
        if (c[i-1] == '0') {
            a[i] = '1';
        } else if (c[i-1] == '1') {
            a[i] = (b[i] == '0'? '0' : '1');
        } else {
            a[i] = (b[i] == '1'? '0' : '1');
        }
        c[i] = a[i]-'0'+b[i];
    }
    cout << a << endl;
}

