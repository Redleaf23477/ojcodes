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
vector<int> arr;

void init() {
    cin >> n;
    arr.assign(n, 0); 
    for (auto &x : arr) cin >> x;
}

void process() {
    vector<int> ans(n, -1);
    function<void(int,int,int)> dfs = [&](int l, int r, int d) {
        if (r-l < 0) return;
        int rt = max_element(arr.begin()+l, arr.begin()+r+1) - arr.begin();
        ans[rt] = d;
        dfs(l, rt-1, d+1);
        dfs(rt+1, r, d+1);
    };
    dfs(0, n-1, 0);
    for (auto &&x : ans) cout << x << " ";
    cout << endl;
}

