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

int n, m; 
vector<int> cnt;

void init() {
    cin >> n >> m;
    cnt.assign(m, 0); {
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x%m]++;
        }
    }
}

void process() {
    int ans = 0;
    ans += (cnt[0] > 0);
    if (m % 2 == 0) {
        ans += (cnt[m/2] > 0); 
    }
    for (int i = 1; i < (m+1)/2; i++) {
        int big = max(cnt[i], cnt[m-i]), small = min(cnt[i], cnt[m-i]);
        if (small > 0) ans++, big -= small+1;
        if (big > 0) ans += big;
    }
    cout << ans << endl;
}

