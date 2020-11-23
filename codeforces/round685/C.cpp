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

int n, k;
string s, t;

void init() {
    cin >> n >> k >> s >> t;
}

void process() {
    vector<int> a(27, 0), b(26, 0);
    for (auto c : s) a[c-'a']++;
    for (auto c : t) b[c-'a']++;

    bool good = true;
    for (int i = 0; i < 26 && good; i++) {
        if (a[i] < b[i]) good = false;
        else {
            a[i] -= b[i];
            if (a[i] % k == 0) a[i+1] += a[i];
            else good = false;
        }
    }
    if (good) cout << "Yes" << endl;
    else cout << "No" << endl;
}

