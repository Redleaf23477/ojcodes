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

int n, m;
vector<int> a, b, p;

void init() {
    cin >> n >> m;
    a.resize(n); for (auto &x : a) cin >> x;
    b.resize(n); for (auto &x : b) cin >> x;
    p.resize(m); for (auto &x : p) cin >> x;
}

void process() {
    bool good = true;
    vector<int> ans(m, -1);

    map<int,int> colpos;
    map<int,vector<int>> mp; {  // color -> still need
        for (int i = 0; i < n; i++) {
            if (mp.count(b[i]) == 0) mp[b[i]] = vector<int>();
            if (a[i] != b[i]) mp[b[i]].emplace_back(i);
            colpos[b[i]] = i;
        }
    }

    int canDiscard = -1;
    for (int i = m-1; i >= 0; i--) {
        if (mp.count(p[i]) == 0) {
            if (canDiscard == -1) { good = false; break; }
            else ans[i] = canDiscard;
        } else {
            auto &arr = mp[p[i]];
            if (arr.size() > 0) {
                canDiscard = ans[i] = arr.back();
                arr.pop_back();
            } else {
                canDiscard = ans[i] = colpos[p[i]];
            }
        }
    }
    for (auto [col, cnt] : mp) {
        if (cnt.size() != 0) good = false;
    }
    
    if (good) {
        cout << "YES" << endl;
        for (auto x : ans) cout << x+1 << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

