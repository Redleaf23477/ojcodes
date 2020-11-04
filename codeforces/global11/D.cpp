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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
vector<int> arr;

void init() {
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process() {
    if(n == 1) {
        cout << 0 << endl; return;
    }
    vector<vector<int>> ans;

    auto locate = [&](int x, int y) {
        int l = -1, r = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == x) {
                l = i; break;
            }
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] == y) {
                r = i; break;
            }
        }
        return make_tuple(l, r);
    };

    auto rearrange = [&](int l, int r, int x) {
        vector<int> tmp;
        // case: l ... r ... x
        if(l <= r && r < x) {
            if(l > 0) tmp.emplace_back(l);
            for(int i = 0; i < (r-l+1); i++) tmp.emplace_back(1);
            tmp.emplace_back(x-r);
            if(x != n-1) tmp.emplace_back(n-1-x);
        }
        // case: x ... r ... l
        else if(x < r && r <= l) {
            if(x > 0) tmp.emplace_back(x);
            tmp.emplace_back(r-x);
            for(int i = 0; i < (l-r+1); i++) tmp.emplace_back(1);
            if(l != n-1) tmp.emplace_back(n-1-l);
        }
        // case: x ... l ... r
        else if(x < l && l <= r) {
            if(x > 0) tmp.emplace_back(x);
            tmp.emplace_back(l-x);
            tmp.emplace_back(r-l+1);
            if(r != n-1) tmp.emplace_back(n-1-r);
        }
        // case: r ... l ... x
        else if(r <= l && l < x) {
            if(r > 0) tmp.emplace_back(r);
            tmp.emplace_back(l-r+1);
            tmp.emplace_back(x-l);
            if(x != n-1) tmp.emplace_back(n-1-x);
        }
        ans.emplace_back(tmp);

        /*
        cerr << "tmp = ";
        for(auto x : tmp) cerr << x << " ";
        cerr << endl;
        */

        vector<int> nxt;
        reverse(tmp.begin(), tmp.end());
        int idx = n;
        for(auto len : tmp) {
            idx -= len;
            for(int i = idx; i < idx+len; i++) nxt.emplace_back(arr[i]);
        }
        arr = nxt;

        /*
        cerr << "nxt = ";
        for(auto x : nxt) cerr << x << " ";
        cerr << endl;
        */
    };

    for(int i = 1; i < n; i++) {
        auto [l, r] = locate(1, i);
        auto [x, _] = locate(i+1, i+1);
        /*
        cerr << var(i) << var(l) << var(r) << var(x) << endl;
        */
        rearrange(l, r, x);
    }
    // reverse if needed
    if(arr[0] == n) {
        ans.emplace_back(vector<int>(n, 1));
    }

    cout << ans.size() << endl;
    for(auto &a : ans) {
        cout << a.size();
        for(auto x : a) cout << " " << x;
        cout << endl;
    }
}

