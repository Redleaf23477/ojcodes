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
    int n; cin >> n;
    vector<LL> arr(n); for (auto &x : arr) cin >> x;
    vector<bool> flg(n, false);
    LL sum = 0;
    for (int i = 1; i < n-1; i++) {
        if (arr[i] > arr[i+1] && arr[i] > arr[i-1]) {
            sum += 1;
            flg[i] = true;
        }
        if (arr[i] < arr[i+1] && arr[i] < arr[i-1]) {
            sum += 1;
            flg[i] = true;
        }
    }
    LL ans = sum;
    for (int i = 1; i < n-1; i++) {
        if (flg[i] == false) continue;
        LL tmp = arr[i], sub = 0, add = 0;
        for (int j = i-1; j <= i+1; j++) {
            if (flg[j]) sub += 1;
        }
        // set to arr[i-1]
        arr[i] = arr[i-1], add = 0;
        for (int j = i-1; j <= i+1; j++) {
            if (j-1 >= 0 && j+1 < n) {
                if (arr[j] > arr[j-1] && arr[j] > arr[j+1]) add += 1;
                if (arr[j] < arr[j-1] && arr[j] < arr[j+1]) add += 1;
            }
        }
        ans = min(ans, sum - sub + add);
        // set to arr[i+1]
        arr[i] = arr[i+1], add = 0;
        for (int j = i-1; j <= i+1; j++) {
            if (j-1 >= 0 && j+1 < n) {
                if (arr[j] > arr[j-1] && arr[j] > arr[j+1]) add += 1;
                if (arr[j] < arr[j-1] && arr[j] < arr[j+1]) add += 1;
            }
        }
        ans = min(ans, sum - sub + add);
        // reset
        arr[i] = tmp;
    }
    cout << ans << endl;
}
