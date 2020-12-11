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
    int T = 1;
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

int highbit(LL x) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if ((x>>i)&1) ans = i;
    }
    return ans;
}

void process() {
    vector<vector<int>> bucket(32, vector<int>());
    for (int i = 0; i < n; i++) {
        int b = highbit(arr[i]);
        bucket[b].emplace_back(arr[i]);
    }
    for (auto b : bucket) {
        if (b.size() > 2) {
            cout << 1 << endl; return;
        }
    }
    // n <= 64
    int ans = 2*n;
    for (int i = 0; i < n; i++) {
        for (int l = 0; l <= i; l++) {
            // xor(arr[l] ... arr[i])
            LL a = 0; for (int j = l; j <= i; j++) a ^= arr[j];
            for (int r = i+1; r < n; r++) {
                // xor(arr[i+1] ... arr[r])
                LL b = 0; for (int j = i+1; j <= r; j++) b ^= arr[j];
                if (a > b) {
                    ans = min(ans, (i-l) + (r-i-1));
                }
            }
        }
    }
    if (ans == 2*n) cout << -1 << endl;
    else cout << ans << endl;
}

