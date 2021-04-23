// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// variadic print template, requires c++17
template<typename Sep, typename Head, typename... Tail>
void fold_print(Sep sep, Head&& h, Tail&&... args) {
    ((std::cerr << h) << ... << (std::cerr << sep, args));
}
#ifdef REDLEAF_LOCAL
#define debug(...) do {                                     \
    std::cerr << "[DEBUG:" << __LINE__ << "] ";             \
    std::cerr << "(" << #__VA_ARGS__ ") = (";               \
    fold_print(", ", __VA_ARGS__);                          \
    std::cerr << ")\n";                                     \
    std::cerr.flush();                                      \
} while (0)
#define info(...) do {                                      \
    std::cerr << "[INFO:" << __LINE__ << "] ";              \
    fold_print(" ", __VA_ARGS__);                           \
    std::cerr << "\n";                                      \
    std::cerr.flush();                                      \
} while (0)
#else
#define debug(...) do { } while (0)
#define info(...) do { } while (0)
#endif
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

const int N = 100005;
vector<int> sp(N, 0);
void buildsp() {
    iota(range(sp), 0);
    for (LL i = 2; i < N; i++) {
        if (sp[i] != i) continue;
        for (LL j = i*i; j < N; j += i) {
            if (sp[j] == j) sp[j] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    buildsp();
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
    arr.assign(n, 0); for (auto &x : arr) cin >> x;
}

void process() {
    int lgn = log2(n)+2;
    function<set<int>(int)> decomp = [&](int x) {
        set<int> ans;
        while (x > 1) {
            ans.insert(sp[x]);
            x /= sp[x];
        }
        return ans;
    };
    function<void(int,set<int>&)> remove = [&](int x, set<int> &fac) {
        set<int> fps = decomp(x);
        for (auto p : fps) {
            assert(fac.count(p) != 0 && "prime factor not in fac");
            fac.erase(p);
        }
    };
    function<void(vector<int>&)> findJump = [&](vector<int> &dp) {
        queue<int> window;
        set<int> fac;
        for (int i = 0; i < n; i++) {
            set<int> pfs = decomp(arr[i]);
            for (auto p : pfs) {
                while (fac.count(p) != 0) {
                    remove(arr[window.front()], fac);
                    dp[window.front()] = i;
                    window.pop();
                }
                fac.insert(p);
            }
            window.push(i);
        }
    };
    vector<vector<int>> jump(lgn, vector<int>(n, n)); {
        // jump[0][i]
        findJump(jump[0]);
        /*
        cerr << "jump[0] = ";
        for (auto x : jump[0]) cerr << x << " ";
        cerr << endl;
        */
        // doubling jump table
        for (int lg = 1; lg < lgn; lg++) {
            for (int i = 0; i < n; i++) {
                if (jump[lg-1][i] < n) jump[lg][i] = jump[lg-1][jump[lg-1][i]];
            }
        }
        /*
        for (int i = 0; i < 3; i++) {
            cerr << "jump[" << i << "] = ";
            for (auto x : jump[i]) cerr << x << " ";
            cerr << endl;
        }
        */
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        debug(l, r);
        int cnt = 0;
        for (int p = l; p <= r; ) {
            int pw = 0;
            while (jump[pw+1][p] <= r) pw++;
            cnt += 1<<pw;
            p = jump[pw][p];
        }
        cout << cnt << endl;
    }
}

