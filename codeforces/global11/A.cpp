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
    vector<int> pos, neg, zero;
    int sum_p = 0, sum_n = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x < 0) sum_n += x, neg.emplace_back(x);
        else if(x > 0) sum_p += x, pos.emplace_back(x);
        else zero.emplace_back(x);
    }
    if(sum_p + sum_n == 0) {
        cout << "NO" << endl;
    } else if(sum_p + sum_n < 0) {
        cout << "YES" << endl;
        for(auto x : neg) cout << x << " ";
        for(auto x : pos) cout << x << " ";
        for(auto x : zero) cout << x << " ";
        cout << endl;
    } else {
        cout << "YES" << endl;
        for(auto x : pos) cout << x << " ";
        for(auto x : neg) cout << x << " ";
        for(auto x : zero) cout << x << " ";
        cout << endl;
    }
}

