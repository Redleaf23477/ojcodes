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
    int l = str.find('('), r = str.find(')');
    int mn = min(l, r), mx = max(l, r);
    int a = mn-0, b = mx-mn-1, c = str.size()-1-mx;
    if (l < r) {
        if ((a + b + c)%2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        if (a == 0 || c == 0) cout << "NO" << endl;
        else if ((a+b+c)%2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
