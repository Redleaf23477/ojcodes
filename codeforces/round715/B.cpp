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
    init();
    for (int t = 1; t <= T; t++) {
        process();
    }
    cout.flush();
    return 0;
}

vector<LL> pw(65, 1), pre(65, 1);

void init() {
    for (int i = 1; i < 64; i++) pw[i] = 2*pw[i-1];
}

void process() {
    LL n, k; cin >> n >> k;
    vector<int> ans(n, 0);
    int i = 0, put = 1;
    while (i < n) {
        if (n-i < 64 && k > pw[n-i-1]) { cout << -1 << endl; return; }
        

        if (n-i >= 64) {
            ans[i] = put, i++, put++;
            continue;
        }

        int j = 1;
        while (n-i-j-1 >= 0 && k > pw[n-i-j-1]) {
            k -= pw[n-i-j-1], j++;
        }
        for (int w = j-1; w >= 0; w--) {
            ans[i++] = put+w;
        }
        put += j;

    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

