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
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp.count(x) == 0) mp[x] = 0;
        mp[x]++;
    }
    for (auto &[a, b] : mp) {
        cout << a << " ";
        b--;
    }
    for (auto &[a, b] : mp) {
        while (b--) cout << a << " ";
    }
    cout << endl;
}

