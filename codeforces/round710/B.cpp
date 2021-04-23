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

int n, k;

int run(string str) {
    int prv = -1, ans = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == '.') continue;
        if (prv == -1) {
            ans++, prv = i, str[i] = 'x';
        }
        for (int j = min(n-i-1, k); j >= 1; j--) {
            if (str[i+j] == '*') {
                ans++, prv = i+j, str[i+j] = 'x';
                i = i+j-1;
                break;
            }
        }
    }
    return ans;
}

void process() {
    cin >> n >> k;
    string str; cin >> str;
    int ans = run(str);
    reverse(range(str));
    ans = min(ans, run(str));
    cout << ans << endl;
}

