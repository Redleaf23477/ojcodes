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

void init() {
}

LL inversion(vector<LL> &arr) {
    vector<LL> buf(arr.size());
    function<LL(int,int)> f = [&](int l, int r) {
        if (l == r) return 0ll;
        int mid = (l + r) / 2;
        LL ans = f(l, mid) + f(mid + 1, r);
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) buf[k++] = arr[i++];
            else ans += (mid - i + 1), buf[k++] = arr[j++];
        }
        while (i <= mid) {
            buf[k++] = arr[i++];
        }
        while (j <= r) {
            buf[k++] = arr[j++];
        }
        for (int i = l; i <= r; i++) {
            arr[i] = buf[i];
        }
        return ans;
    };
    return f(0, arr.size() - 1);
}

void process() {
    int n; cin >> n;
    using P = tuple<LL,LL>;
    vector<P> arr(n); {
        for (auto &[a, b] : arr) cin >> a;
        for (auto &[a, b] : arr) cin >> b;
        sort(range(arr), [](const P &lhs, const P &rhs) {
            auto [la, lb] = lhs;
            auto [ra, rb] = rhs;
            if (la != ra) return la < ra;
            else return lb > rb;
        });
    }
    LL ans = n; {
        vector<LL> sec(n); {
            for (int i = 0; i < n; i++) {
                sec[i] = get<1>(arr[i]);
            }
        }
        ans += inversion(sec);
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] == arr[i+1]) {
                LL len = 2;
                while (i+len < n && arr[i] == arr[i+len]) len++;
                ans += len * (len-1) / 2;
                i += len - 1;
            }

        }
    }
    cout << ans << endl;
}

