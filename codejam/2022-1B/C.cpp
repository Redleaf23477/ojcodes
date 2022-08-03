#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

// Tiger blue solution

constexpr int BIT_NUM = 8;

int get_state(int x) {
    constexpr int mask = (1 << BIT_NUM) - 1;
    return min(x, mask ^ x);
}

vector<int> seen_states;

vector<vector<int>> arr(BIT_NUM+1);

int rotate(int x) {
    int b = x & 1;
    x >>= 1;
    x += b << (BIT_NUM-1);
    return x;
}

void init() {
    vector<set<int>> tmp_set(BIT_NUM+1);
    for (int i = 0; i < (1 << BIT_NUM); i++) {
        int b = __builtin_popcount(i);
        int mn = i;
        for (int r = 1, j = rotate(i); r < BIT_NUM; r++, j = rotate(j)) {
            mn = min(mn, j);
        }
        tmp_set[b].insert(mn);
    }
    for (int i = 0; i <= BIT_NUM; i++) {
        arr[i] = vector<int>(tmp_set[i].begin(), tmp_set[i].end());
//        cerr << "arr[" << i << "].size() = " << arr[i].size() << endl;
    }

    set<int> s;
    for (int i = 0; i <= BIT_NUM; i++) {
        for (auto x : arr[i]) {
            s.insert(get_state(x));
        }
    }
    cerr << "total states = " << s.size() << endl;
}

string rand_int_with_ones(int b) {
    int ans = -1, ans_seen = 0;
    for (auto x : arr[b]) {
        int s = get_state(x);
        if (ans == -1 || seen_states[s] < ans_seen) {
            ans = x, ans_seen = seen_states[s];
        }
    }
    seen_states[get_state(ans)] += 1;
    return bitset<BIT_NUM>(ans).to_string();
}

void solve() {
    seen_states.assign((1 << BIT_NUM), 0);
    cout << "00000000" << endl;
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        else if (n == -1) exit(0);
        string sol;
        sol = rand_int_with_ones(n);
//        cerr << "n = " << n << ", sol = " << sol << endl;
        cout << sol << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    init();
    for (int t = 1; t <= T; t++) {
        solve();
    }
}


