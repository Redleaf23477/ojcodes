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

LL extgcd(LL a, LL b, LL &x, LL &y) {
    LL d = a;
    if (b!=0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    } else {
        x = 1, y = 0;
    }
    return d;
}

LL mod_inv(LL a, LL m) {
    LL x, y;
    LL g = extgcd(a, m, x, y);
    if (g != 1) return -1;
    return (m+x%m)%m;
}

int n;

void init() {
    cin >> n;
}

void process() {
    vector<int> ans {1};
    vector<int> x;
    for (int i = 2; i < n; i++) {
        LL inv = mod_inv(i, n);
//        if (i == inv) cerr << var(i) << var(inv) << endl;
        if (inv == -1) continue;
        else if (i == inv) x.emplace_back(i);
        else ans.emplace_back(i);
    }
    if (x.size() > 1) {
        for (auto y : x) ans.push_back(y);
    }
    sort(range(ans));
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

