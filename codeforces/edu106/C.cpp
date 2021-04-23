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

LL n;
vector<LL> cost;

void init() {
    cin >> n;
    cost.assign(n, 0); for (auto &c : cost) cin >> c;
}

void process() {
    LL ans = 1ll<<60;
    LL mn[2] {cost[0], cost[1]}, sum[2] {cost[0], cost[1]}, sz[2] {1, 1};
    ans = cost[0]*n + cost[1]*n;
    for (int i = 2; i < n; i++) {
        int idx = i%2;
        mn[idx] = min(mn[idx], cost[i]), sum[idx] += cost[i], sz[idx]++;
        LL tmp = 0; {
            for (int j = 0; j < 2; j++) {
                tmp += sum[j] + (n-sz[j])*mn[j];
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

