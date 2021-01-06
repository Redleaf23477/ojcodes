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
    string str; cin >> str;
    int n = str.size();
    if (n == 1) { cout << 0 << endl; return; }
    if (n == 2) { cout << (str[0] == str[1]? 1 : 0) << endl; return; }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i-1] && str[i-1] != 'X') {
            str[i] = 'X', ans++;
        }
        if (i > 1 && str[i] == str[i-2] && str[i-2] != 'X') {
            str[i] = 'X', ans++;
        }
    }
    cout << ans << endl;
}

