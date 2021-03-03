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
    int n, m, e; cin >> n >> m >> e;
    vector<int> u(e), v(e), du(n), dv(m);
    for (int i = 0; i < e; i++) {
        cin >> u[i]; u[i]--;
        du[u[i]]++;
    }
    for (int i = 0; i < e; i++) {
        cin >> v[i]; v[i]--;
        dv[v[i]]++;
    }
    LL ans = 0;
    for (int i = 0; i < e; i++) {
        ans += (e - du[u[i]] - dv[v[i]] + 1);
    }
    cout << ans/2 << endl;
}

