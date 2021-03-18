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

const int N = 10000007;
int sp[10000];
vector<int> prime;

void build() {
    iota(sp, sp+10000, 0);
    for (LL i = 2; i*i < N; i++) {
        if (sp[i] != i) continue;
        for (LL j = i*i; j < 10000; j += i) {
            sp[j] = i;
        }
    }
    for (int i = 2; i*i < N; i++) {
        if (sp[i] == i) prime.emplace_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    build();
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, k; 
vector<LL> arr;

void init() {
    cin >> n >> k;
    arr.assign(n, 0);
    for (auto &x : arr) {
        cin >> x;
    }
}

void print(map<LL,int> mp) {
    cerr << "{";
    for (auto [k, v] : mp) cerr << "(" << k << "," << v << ")";
    cerr << "}";
    cerr << endl;
}

void process() {
    int ans = 1;
    set<map<LL,int>> s;
    for (auto x : arr) {
        map<LL,int> mp;

        for (auto p : prime) {
            if (x % p == 0) mp[p] = 0;
            while (x % p == 0) mp[p]++, x /= p;
        }
        if (x != 1) {
            if (mp.count(x) != 0) mp[x] = 0;
            mp[x]++;
        }

        map<LL,int> fac; 

        for (auto [f, c] : mp) {
            if (c%2 == 1) fac[f] = 1;
        }

        // print(mp); print(fac);

        if (s.count(fac) != 0) {
            ans++;
            s.clear();
        }
        s.insert(fac);
    }
    cout << ans << endl;
}
