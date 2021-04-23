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

void init() {
}

void small(const int n, const vector<int> Q) {
    vector<int> ans(n, 0);
    set<int> s; for (int i = 0; i < n; i++) s.insert(i+1);
    ans[0] = Q[0]; s.erase(Q[0]);
    for (int i = 1, mx = Q[0]; i < n; i++) {
        if (Q[i] != mx) {
            ans[i] = mx = Q[i];
            s.erase(ans[i]);
        } else {
            ans[i] = *s.begin();
            s.erase(ans[i]);
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

void big(const int n, const vector<int> Q) {
    vector<int> ans(n, 0);
    set<int> s; for (int i = 0; i < n; i++) s.insert(i+1);
    ans[0] = Q[0]; s.erase(Q[0]);
    for (int i = 1, mx = Q[0]; i < n; i++) {
        if (Q[i] != mx) {
            ans[i] = mx = Q[i];
            s.erase(ans[i]);
        } else {
            auto it = s.upper_bound(mx); it--;
            ans[i] = *it; 
            s.erase(ans[i]);
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

void process() {
    int n; cin >> n;
    vector<int> q(n); for (auto &x : q) cin >> x;
    small(n, q);
    big(n, q);
}

