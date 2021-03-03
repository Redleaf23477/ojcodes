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

int n, q; 
vector<int> arr;

void init() {
    cin >> n >> q;
    arr.assign(n, 0); for (int i = 0; i < n; i++) cin >> arr[i];
}

void process() {
    int zero = 0, one = 0;
    for (auto &&x : arr) zero += (x==0), one += (x==1);
    while (q--) {
        int t, k; cin >> t >> k;
        if (t == 2) {
            if (k <= one) cout << 1 << endl;
            else cout << 0 << endl;
        } else {
            if (arr[k-1] == 1) arr[k-1] = 0, one--, zero++;
            else arr[k-1] = 1, one++, zero--;
        }
    }
}

