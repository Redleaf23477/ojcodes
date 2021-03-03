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

int n; 
vector<int> arr;

void init() {
    cin >> n; n *= 2;
    arr.resize(n); for (auto &x : arr) cin >> x;
}

void process() {
    auto run = [&](int x) -> vector<pair<int,int>> {
        vector<pair<int,int>> res;
        multiset<pair<int,int>> s; {
            for (int i = 0; i < n; i++) s.emplace(arr[i], i);
        }
        while (s.size()) {
            int b, i; { auto it = s.end(); it--; b = it->first, i = it->second; s.erase(it); }
            int a = x-b, j; {
                auto it = s.lower_bound(make_pair(a, 0));
                if (it == s.end() || it->first != a) {
                    res.clear(); break;
                } else {
                    j = it->second; s.erase(it);
                }
            }
            res.emplace_back(a, b);
            x = b;
        }
        return res;
    };
    auto mx = max_element(arr.begin(), arr.end());
    for (auto it = arr.begin(); it != arr.end(); it++) {
        if (it == mx) continue;
        auto res = run(*it + *mx);
        if (res.size()) {
            cout << "YES" << endl;
            cout << *it + *mx << endl;
            for (auto [i, j] : res) {
                cout << i << " " << j << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
}
