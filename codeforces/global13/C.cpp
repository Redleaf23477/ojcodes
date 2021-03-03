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

int n;
vector<LL> arr;

void init() {
    cin >> n;
    arr.assign(n, 0); for (auto &x : arr) cin >> x;
}

void process() {
    LL ans = 0;
    vector<int> jmp(n, 0);
    for (int i = 0; i < n; i++) {
        // deal with jumps to index i
        while (jmp[i] > 0 && arr[i] > 1) {
            if (i+arr[i] < n) jmp[i+arr[i]]++;
            arr[i]--, jmp[i]--;
        }
        if (jmp[i] > 0) {
            if (i+1 < n) jmp[i+1] += jmp[i];
        }
        // jump to next
        if (arr[i] > n) {
            ans += arr[i]-n;
            arr[i] = n;
        }
        while (arr[i] > 1) {
            if (i+arr[i] < n) jmp[i+arr[i]]++;
            arr[i]--;
            ans++;
        }
    }
    cout << ans << endl;
}

