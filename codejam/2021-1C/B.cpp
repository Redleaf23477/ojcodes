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
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

string str;
int n;

void init() {
    cin >> str;
    n = str.size();
}

bool lt(string &lhs, string &rhs) {
    if (lhs.size() != rhs.size()) return lhs.size() < rhs.size();
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) return lhs[i] < rhs[i];
    }
    return false;
}

LL str2ll(string &str) {
    stringstream ss(str);
    LL l; ss >> l;
    return l;
}

string ll2str(LL l) {
    stringstream ss;
    ss << l;
    string ans; 
    ss >> ans;
    return ans;
}

void process() {
    bool noans = true;
    string ans;
    function<void(int)> run = [&](int len) {
        string res, sub = str.substr(0, len);
        res += sub;
        LL prev = str2ll(sub);
        while (res.size() < str.size()) {
            prev += 1;
            sub = ll2str(prev);
            res += sub;
        }
        debug("run", len, res);
        if (res != str && !lt(res, str)) {
            if (noans || lt(res, ans)) swap(ans, res), noans = false;
        }
    };
    function<void(int)> run_adv = [&](int len) {
        string res, sub = str.substr(0, len);
        LL prev = str2ll(sub) + 1;
        sub = ll2str(prev);
        res += sub;
        int adv = (sub.size() > n);
        while (res.size() < str.size() + adv) {
            prev += 1;
            sub = ll2str(prev);
            res += sub;
        }
        debug("run_adv", len, res);
        if (res != str && !lt(res, str)) {
            if (noans || lt(res, ans)) swap(ans, res), noans = false;
        }
    };
    for (int len = 1; len < n; len++) {
        run(len);
        run_adv(len);
    }
    cout << ans << endl;
}

