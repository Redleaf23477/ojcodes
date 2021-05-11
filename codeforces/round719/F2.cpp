// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
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

int QUERY(int l, int r) {
    l++, r++;
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    return r-l+1-x;
}

void REPORT(int x) { 
    cout << "! " << x+1 << endl;
}

struct Seg1D {
    int n;
    vector<int> st;
    void init(int _n) {
        n = _n;
        st.assign(4*n, -1);
    }
    void binsearch(int l, int r, int idx, int k) {
        if (l == r) {
            REPORT(l); 
            modify(idx);
            return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        if (st[lson] == -1) st[lson] = QUERY(l, mid);
        debug(l, mid, st[lson], k);
        if (k <= st[lson]) binsearch(l, mid, lson, k);
        else binsearch(mid+1, r, rson, k-st[lson]);
    }
    void binsearch(int k) { return binsearch(0, n-1, 1, k); }
    void modify(int idx) {
        if (idx <= 0) return;
        if (st[idx] != -1) st[idx] -= 1;
        modify(idx/2);
    }
};

int n, t;
Seg1D seg;

void init() {
    cin >> n >> t;
    seg.init(n);
}

void process() {
    int k;
    while (t--) {
        cin >> k;
        seg.binsearch(k);
    }
}

