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
    int n; cin >> n; n += 2;
    vector<LL> arr(n); for (auto &x : arr) cin >> x;
    sort(range(arr));
    LL sum = accumulate(range(arr), 0);
    for (int i = 0; i < n-1; i++) {
        LL x = arr[i];
        LL s2 = sum - x;
        if (s2 % 2 != 0) continue;
        s2 /= 2;
        if (s2 == arr[n-1]) {
            for (int j = 0; j < n-1; j++) {
                if (i != j) cout << arr[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    LL x = arr[n-1], s2 = sum - x;
    if (s2 % 2 != 0) { cout << -1 << endl; return; }
    if (arr[n-2] == s2 / 2) {
        for (int i = 0; i < n-2; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

