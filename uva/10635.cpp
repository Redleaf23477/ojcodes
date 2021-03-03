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
        cout << "Case " << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, p, q;
vector<int> a, b;

void init() {
    cin >> n >> p >> q;
    a.assign(p+1, 0); for (int i = 0; i <= p; i++) cin >> a[i];
    b.assign(q+1, 0); for (int i = 0; i <= q; i++) cin >> b[i];
}

void process() {
    vector<int> relabel(n*n+1, -1);
    for (int i = 0; i <= p; i++) {
        relabel[a[i]] = i;
    }
    vector<int> arr;
    for (int i = 0; i <= q; i++) {
        int x = relabel[b[i]];
        if (x >= 0) arr.emplace_back(x);
    }
    /*
    cerr << "arr = ";
    for (auto x : arr) cerr << x << " ";
    cerr << endl;
    */
    // lis
    vector<int> dp; dp.emplace_back(-1);
    for (auto x : arr) {
        int i = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (i == dp.size()) dp.emplace_back(x);
        else if(x < dp[i]) dp[i] = x;
    }
    cout << dp.size()-1 << endl;
}

