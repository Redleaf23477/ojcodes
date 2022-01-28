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

void process() {
    string str; cin >> str;
    LL K; cin >> K;
    vector<LL> has(str.size() + 1, 0); 
    vector<LL> pos(str.size() + 1, 0); {
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] == 'Y') {
                pos[i+1] = i+1;
                has[i+1] = 1;
            }
        }
    }
    vector<LL> pre_has(pos.size(), 0);
    vector<LL> pre_pos(pos.size(), 0); {
        partial_sum(range(has), pre_has.begin());
        partial_sum(range(pos), pre_pos.begin());
    }
    auto good = [&](size_t L, size_t R, LL mid) {
        LL cnt = pre_has[mid] - pre_has[L-1];
        LL pos_sum = pre_pos[mid] - pre_has[L-1];
        LL cost = pos_sum - L * cnt + cnt - cnt * (cnt-1) / 2;
        return cost <= K;
    };
    auto run = [&](size_t L, size_t R) {
        LL l = L, r = R, mid, ans = L;
        while (l <= r) {
            mid = (l + r) / 2;
            if (good(L, R, mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return pre_has[ans] - pre_has[L-1];
    };
    LL ans = 0;
    for (size_t i = 1, j = 1; i < pos.size(); i++) {
        if (has[i] == 1) {
            if (j < i) j = i;
            while (j+1 < pos.size() && has[j+1] == 1) j++;
            debug(i, j);
            ans = max(ans, (LL)(j-i+1) + run(j+1, pos.size()-1));
            i = j;
        } else {
            debug(i);
            ans = max(ans, run(i, pos.size()-1));
        }
    }
    cout << ans << endl;
}

