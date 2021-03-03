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

constexpr int N = 200005;
int n;
array<int, N> dp, cnt;

void init() {
    cin >> n;
    fill(range(dp), 0), fill(range(cnt), 0);
    for (int i = 0, x; i < n; i++) {
        cin >> x; cnt[x]++;
    }
}

void process() {
    for (int i = 1; i < N; i++) {
        if (cnt[i] == 0) continue;
        dp[i] = max(dp[i], cnt[i]);
        for (int j = 2*i; j < N; j+=i) {
            if (cnt[j] != 0) dp[j] = max(dp[j], cnt[j]+dp[i]);
        }
    }
    cout << n - *max_element(range(dp)) << endl;
}
