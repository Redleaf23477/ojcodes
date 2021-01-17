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
    init();
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

vector<LL> pw2;

void init() {
    pw2.assign(30, 1); 
    for (int i = 1; i < 30; i++) pw2[i] = pw2[i-1]*2;
}

void process() {
    int n; cin >> n;
    vector<LL> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];
    vector<LL> ans(n);
    for (int i = 0; i < n; i++) {
        LL d = arr[i]-1, p = 0;
        for (int j = 1; j < 30; j++) {
            LL tmp = abs(pw2[j] - arr[i]);
            if (tmp < d) d = tmp, p = j;
        }
        ans[i] = pw2[p];
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

