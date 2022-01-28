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

vector<string> arr(10000);

void init() {
    int u; cin >> u;
    for (int i = 0; i < 10000; i++) {
        int x; cin >> x;
        cin >> arr[i];
    }
}

void process() {
    set<char> occur; {
        for (auto&& str : arr) {
            for (auto c : str) occur.insert(c);
        }
        /*
        cerr << "occur: ";
        for (auto x : occur) cerr << x << " ";
        cerr << endl;
        */
    }
    map<char,int> freq; {
        for (auto&& str : arr) {
            if (freq.count(str[0]) == 0) freq[str[0]] = 0;
            freq[str[0]]++;
        }
    }
    vector<pair<int,char>> pa; {
        for (auto [ch, cnt] : freq) {
            occur.erase(ch);
            pa.emplace_back(cnt, ch);
            debug(ch, cnt);
        }
        /*
        cerr << "pa = ";
        for (auto x : pa) cerr << "(" << x.first << "," << x.second << ")";
        cerr << endl;
        */
    }
    string ans(10, 'x'); {
        ans[0] = *occur.begin();
        sort(range(pa));
        reverse(range(pa));
        for (int i = 0; i < 9; i++) {
            ans[i+1] = pa[i].second;
        }
    }
    cout << ans << endl;
}

