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
vector<LL> w, deg;

void init() {
    cin >> n;
    w.assign(n, 0), deg.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        deg[u]++, deg[v]++;
    }
}

void process() {
    LL ans = 0; for (auto x : w) ans += x;
    cout << ans;
    priority_queue<tuple<LL,LL>> pq; // (w, idx)
    for (int i = 0; i < n; i++) {
        if (deg[i] > 1) pq.emplace(w[i], i);
    }
    for (int i = 0; i < n-2; i++) {
        if (!pq.empty()) {
            auto [wei, idx] = pq.top();
            ans += wei;
            deg[idx]--;
            if (deg[idx] == 1) pq.pop();
        }
        cout << " " << ans;
    }
    cout << endl;
}

