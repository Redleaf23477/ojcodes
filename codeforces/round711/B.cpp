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

void init() {
}

void process() {
    int n, len; cin >> n >> len;
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    sort(range(arr), greater<int>());
    function<bool(int)> good = [&](int mid) {
        priority_queue<int> pq;
        for (int i = 0; i < mid; i++) pq.push(len);
        for (auto x : arr) {
            if (pq.empty()) return false;
            int mx = pq.top(); pq.pop();
            if (mx < x) return false;
            if (mx > x) pq.push(mx-x);
        }
        return true;
    };
    int low = 1, high = n, mid, ans = -1;
    while (low <= high) {
        mid = (low+high)/2;
        if (good(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}

