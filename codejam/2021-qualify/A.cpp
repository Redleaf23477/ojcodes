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
        cout << "Case #" << t << ": ";
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
    vector<int> arr(n); for (auto &x : arr) cin >> x;
    int ans = 0;
    for (int i = 0, j, mn = 1; i < n-1; i++, mn++) {
        for (j = i; j < n; j++) {
            if (arr[j] == mn) break;
        }
        reverse(arr.begin()+i, arr.begin()+j+1);
        /*
        cerr << var(i) << var(j) << endl;
        for (auto x : arr) cerr << x << " ";
        cerr << endl;
        */
        ans += j-i+1;
    }
    cout << ans << endl;
}

