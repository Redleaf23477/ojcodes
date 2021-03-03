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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, m;
string txt, sub;

void init() {
    cin >> n >> m;
    cin >> txt >> sub;
}

void process() {
    vector<int> l(sub.size(), -1), r(sub.size(), -1); {
        for (int i = 0, j = 0; i < (int)sub.size(); i++, j++) {
            while (txt[j] != sub[i]) j++;
            l[i] = j;
        }
        for (int i = sub.size()-1, j = txt.size()-1; i >= 0; i--, j--) {
            while (txt[j] != sub[i]) j--;
            r[i] = j;
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)sub.size()-1; i++) {
        ans = max(ans, r[i+1]-l[i]);
    }
    cout << ans << endl;
}

