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

int n;
LL M;
vector<LL> a, b;

void init() {
    cin >> n >> M;
    a.assign(n, -1), b.assign(n, -1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
}

void process() {
    using Node = tuple<LL,int>;
    set<Node> b_set; {
        for (int i = 0; i < n; i++) {
            b_set.insert(Node(b[i], i));
        }
    }
    vector<LL> dist(n, -1);
    set<Node> pq;
    vector<int> best_choice(n, -1);
    auto choose_edge = [&](int u) {
        if (b_set.empty()) {
            best_choice[u] = -1;
            return;
        }
        // overflow M if possible
        // otherwise choose smallest
        LL d = M - a[u];
        auto it = b_set.lower_bound(Node(d, 0));
        if (it != b_set.end()) {
            auto [val, idx] = *it;
            best_choice[u] = idx;
        } else {
            it = b_set.begin();
            auto [val, idx] = *it;
            best_choice[u] = idx;
        }
    };
    {
        dist[0] = 0, choose_edge(0);
        int v = best_choice[0];
        LL new_len = (a[0] + b[v]) % M;
        dist[v] = new_len;
        b_set.erase(Node(b[0], 0));
        pq.insert(Node(new_len, 0));
    }
    while (!pq.empty()) {
        auto [len, u] = *pq.begin(); pq.erase(pq.begin());
        int v = best_choice[u];
        LL new_len = dist[u] + (a[u] + b[v]) % M;
        // remove old unused
        if (dist[v] != -1 && dist[v] < new_len) {
            auto it = b_set.find(Node(b[v], v));
            if (it == b_set.end()) {
                choose_edge(u);
            } else {
                b_set.erase(it);
                choose_edge(u);
                b_set.insert(Node(b[v], v));
                cerr << "hahah" << endl;
            }
            v = best_choice[u];
            if (v != -1) {
                new_len = dist[u] + (a[u] + b[v]) % M;
                pq.insert(Node(new_len, u));
                if (dist[v] == -1 || dist[v] > new_len) dist[v] = new_len;
            }
            continue;
        }
        // I find a new shortest path
        if (v == n-1) break;
        // v -> x
        b_set.erase(Node(b[v], v));
        for (auto y : {v, u}) {
            choose_edge(y);
            int x = best_choice[y];
            if (x != -1) {
                new_len = dist[y] + (a[y] + b[x]) % M;
                pq.emplace(Node(new_len, v));
                if (dist[x] == -1 || new_len < dist[x]) {
                    dist[x] = new_len; 
                }
            }
        }
    }
    cout << dist[n-1] << endl;
}

