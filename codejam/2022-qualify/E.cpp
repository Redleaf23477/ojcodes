#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

tuple<int,int> teleport(int v) {
    cout << "T " << v+1 << endl;
    int x, deg; cin >> x >> deg;
    return make_tuple(x-1, deg);
}

tuple<int,int> walk() {
    cout << "W" << endl;
    int x, deg; cin >> x >> deg;
    return make_tuple(x-1, deg);
}

void report(LL E) {
    cout << "E " << E << endl;
}

void solve() {
    int N, K; cin >> N >> K;
    int x, d; cin >> x >> d; x -= 1;
    vector<int> deg(N, 0); deg[x] = d;
    vector<vector<int>> timestamp(N);
    timestamp[x].emplace_back(0);

    for (int k = 1; k < K; k++) {
        tie(x, d) = walk();
        deg[x] = d;
        timestamp[x].emplace_back(k);
    }

    int t = -1;
    for (int i = 0; i < N; i++) {
        if (t == -1 || timestamp[i].size() > timestamp[t].size()) t = i;
    }

    
    int sum = 0, cnt = timestamp[t].size() - 1;
    assert(cnt != 0);
    for (size_t i = 1; i < timestamp[t].size(); i++) sum += timestamp[t][i] - timestamp[t][i-1];
    cerr << "t = " << t << ", sum = " << sum << ", cnt = " << cnt << ", deg = " << deg[t] << endl;
    report(sum / (double)cnt * deg[t] / 2.0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

