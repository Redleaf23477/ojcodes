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
vector<LL> arr, premx, sufmx;

void init() {
    cin >> n;
    arr.assign(n, 0), premx.assign(n, 0), sufmx.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    premx[0] = arr[0]; for (int i = 1; i < n; i++) premx[i] = max(arr[i], premx[i-1]);
    sufmx[n-1] = arr[n-1]; for (int i = n-2; i >= 0; i--) sufmx[i] = max(arr[i], sufmx[i+1]);
}

void process() {
    LL sum = 0; for (auto x : arr) sum += x;
    vector<LL> add(n, 0);
    for (int i = 0; i < n; i++) {
        LL mx = 0;
        if (i > 0) mx = max(premx[i-1], mx);
        if (i < n-1) mx = max(sufmx[i+1], mx);
        LL need = mx * (n-1) - (sum - arr[i]);
        if (need == arr[i]) add[i] = 0;
        else if (need > arr[i]) add[i] = need-arr[i];
        else {
            LL tmp = (arr[i] - need) % (n-1);
            if (tmp == 0) add[i] = 0;
            else add[i] = n-1 - tmp;
        }
    }
    LL ans = *max_element(add.begin(), add.end());
    cout << ans << endl;
}

