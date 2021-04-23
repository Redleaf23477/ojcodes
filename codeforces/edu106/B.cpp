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

int n;
string str;

void init() {
    cin >> str;
    n = str.size();
}

void process() {

    function<bool(string&, int)> check = [](string &s, int one) {
        int prev = -5;
        // kill 1
        for (int i = 0; i < one; i++) {
            if (s[i] == '1') {
                if (i-prev <= 1) return false;
                prev = i;
            }
        }
        // kill 0
        for (int i = one; i < n; i++) {
            if (s[i] == '0') {
                if (i-prev <= 1) return false;
                prev = i;
            }
        }
        return true;
    };

    bool good = false;
    for (int i = 0; i <= n && !good; i++) {
        good = check(str, i);
    }
    cout << (good? "YES" : "NO") << endl;
}

