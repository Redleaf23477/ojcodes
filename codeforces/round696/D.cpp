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
vector<LL> arr;

void init() {
    cin >> n;
    arr.resize(n); for (auto &x : arr) cin >> x;
}

void process() {
    vector<LL> pre(n), suf(n); {
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            if (pre[i-1] == -1) pre[i] = -1;
            else if (arr[i] >= pre[i-1]) pre[i] = arr[i] - pre[i-1];
            else pre[i] = -1;
        }
        suf[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (suf[i+1] == -1) suf[i] = -1;
            else if (arr[i] >= suf[i+1]) suf[i] = arr[i] - suf[i+1];
            else suf[i] = -1;
        }
    }
    if (pre[n-1] == 0 || suf[0] == 0) {
        cout << "YES" << endl; return;
    }
    for (int i = 1; i < n; i++) {
        // swap (i-1, i)
        LL left = (i-2 >= 0? pre[i-2] == -1? -1 : arr[i]-pre[i-2] : arr[i]);
        LL right = arr[i-1] - left;
        if (left < 0 || right < 0) continue;
        if (i == n-1) {
            if (right == 0) { cout << "YES" << endl; return; }
        } else {
            if (right == suf[i+1]) { cout << "YES" << endl; return; }
        }
    }
    cout << "NO" << endl;
}

