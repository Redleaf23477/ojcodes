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

int n;
LL m;
vector<LL> a, b;

void init() {
    cin >> n >> m;
    a.resize(n), b.resize(n); {
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
    }
}

void process() {
    vector<LL> one, two; {
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) one.emplace_back(a[i]);
            else two.emplace_back(a[i]);
        }
        sort(one.begin(), one.end(), greater<LL>());
        sort(two.begin(), two.end(), greater<LL>()); 
        /*
        cerr << "one = ";
        for (auto x : one) cerr << x << " ";
        cerr << endl;
        */
        for (int i = 1; i < (int)one.size(); i++) one[i] += one[i-1];
        for (int i = 1; i < (int)two.size(); i++) two[i] += two[i-1];
    }
    constexpr LL INF = 1ll<<60;
    LL ans = INF; {
        auto it = lower_bound(two.begin(), two.end(), m);
        if (it != two.end()) {
            ans = 2*(it-two.begin()+1);
        }
    }
    for (int i = 0; i < (int)one.size(); i++) {
        if (one[i] >= m) {
            ans = min(ans, (LL)i+1); break;
        }
        auto it = lower_bound(two.begin(), two.end(), m-one[i]);
        if (it != two.end()) {
            ans = min(ans, (LL)i+1+2*(it-two.begin()+1));
        }
    }
    cout << (ans == INF? -1 : ans) << endl;
}

