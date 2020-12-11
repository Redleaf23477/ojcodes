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

int n, m, k;
vector<tuple<int,int>> arr;

void init() {
    cin >> n >> m >> k; 
    arr.resize(m);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        arr[i] = make_tuple(l, r);
    }
}

void process() {
    vector<int> eat(n+1, 0);
    for (int l = 1; l+k <= n; l++) {
        int r = l+k-1;
        int sum = 0;
        for (auto [a, b] : arr) {
            int x = max(l, a), y = min(r, b);
            sum += max(0, y-x+1);
        }
        eat[l] = sum;
    }
    cerr << "eat = ";
    for (int i = 1; i+k <= n; i++) cerr << eat[i] << " ";
    cerr << endl;
}

