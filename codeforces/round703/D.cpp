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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, k; 
vector<int> arr;

void init() {
    cin >> n >> k;
    arr.resize(n); for (auto &x : arr) cin >> x;
}

void process() {

    function<int(int)> check = [&](int med) { 
        vector<int> arr2(arr); {
            for (auto &x : arr2) x = (x >= med? 1 : -1);
        }
        vector<int> sum(arr2); {
            for (int i = 1; i < n; i++) sum[i] += sum[i-1];
        }
        vector<int> mn(sum); {
            mn[0] = min(mn[0], 0);
            for (int i = 1; i < n; i++) mn[i] = min(mn[i-1], mn[i]);
        }

        if (sum[k-1] > 0) return true;
        for (int i = k; i < n; i++) {
            if (sum[i] - mn[i-k] > 0) return true;
        }

        return false;
    };

    int l = 1, r = n, mid, ans = -1;
    while (l <= r) {
        mid = (l+r)/2;
        if (check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    cout << ans << endl;
}

