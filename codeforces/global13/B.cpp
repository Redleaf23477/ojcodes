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

LL n, u, v;
vector<LL> arr;

void init() {
    cin >> n >> u >> v;
    arr.assign(n, 0); for (auto && x : arr) cin >> x;
}

void process() {
    vector<int> diff(n, 0); {
        for (int i = 1; i < n; i++) diff[i] = abs(arr[i]-arr[i-1]);
    }
    LL ans = 1ll<<60; {
        for (int i = 1; i < n; i++) {
            if (diff[i] == 0) ans = min(ans, v+min(u,v));
            else if (diff[i] == 1) ans = min(ans, min(u, v));
            else ans = 0;
        }
    }
    cout << ans << endl;
}

