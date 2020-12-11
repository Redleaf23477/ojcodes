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

int n, m;
vector<int> arr;
vector<bool> sorted;

void init() {
    cin >> n >> m;
    arr.assign(n, 0), sorted.assign(n, false);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sorted[n-1] = (arr[n-1] == n);
    for (int i = n-2; i >= 0; i--) {
        sorted[i] = (arr[i] == i+1 && sorted[i+1]);
    }
    /*
    cerr << "sorted = ";
    for (auto x : sorted) cerr << x << " ";
    cerr << endl;
    */
}

void process() {
    int r = n;
    for (int i = n-1; i >= 0; i--) {
        if (sorted[i]) r = i;
        else break;
    }
    int x = 0; double p = (r == 0? 1 : 0);
    while (m--) {
        int len; double pi; cin >> len >> pi;
        if (r == 0) continue;  // already 1.0
        if (len >= r) p = p + (1.0-p)*pi;
    }
    cout << fixed << setprecision(8) << p << endl;
}

