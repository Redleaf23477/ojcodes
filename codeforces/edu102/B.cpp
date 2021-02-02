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

void init() {
}

void process() {
    string s, t; cin >> s >> t;
    if (s.size() > t.size()) swap(s, t);
    string ans = t;
    for (size_t i = 0, j = 0; j < ans.size(); i=(i+1)%s.size(), j++) {
        if (s[i] != ans[j]) {
            ans = "-1"; break;
        }
        if (i+1 != s.size() && j+1 == ans.size()) ans += t;
    }
    cout << ans << endl;
}

