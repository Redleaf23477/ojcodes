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

LL n;
vector<LL> arr;

void init() {
    cin >> n; arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
}

LL run(int be = 1, int skip = 0) {
    LL sum = 0, acc = 0;
    for (int i = be+1; i < n; i++) {
        if (i == skip) continue;
        LL d = arr[be]-(arr[i]+acc);
        sum += abs(d), acc += d;
    }
    return sum;
}

LL case1() {
    LL save = 0, idx = -1;
    for (int i = 1; i < n-1; i++) {
        int prv = i-1, nxt = i+1;
        LL s = abs(arr[i]-arr[prv]) + abs(arr[nxt]-arr[i]) - abs(arr[nxt]-arr[prv]);
        if (s > save) save = s, idx = i;
    }
    if (abs(arr[n-1]-arr[n-2]) > save) idx = n-1, save = abs(arr[n-1]-arr[n-2]);
    return run(0, idx);
}


void process() {
    LL ans = 1ll << 60;
    // case 1: be arr[0]
    ans = min(case1(), ans);
    // case 2: be arr[1]
    ans = min(run(), ans);
    cout << ans << endl;
}

