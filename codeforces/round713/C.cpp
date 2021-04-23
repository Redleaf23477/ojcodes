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

void process() {
    int a, b; cin >> a >> b;
    int n = a+b;
    string str; cin >> str;
    // non ??
    for (int i = 0, j = n-1; i <= j; i++, j--) {
        if (str[i] == '?' && str[j] == '?') continue;
        else if (i == j) {
            if (str[i] == '0') a--;
            else b--;
        } else if (str[i] == '0') {
            if (str[j] == '1') { cout << -1 << endl; return; }
            else if (str[j] == '0') a -= 2;
            else if (str[j] == '?') a -= 2, str[j] = '0';
        } else if (str[i] == '1') {
            if (str[j] == '0') { cout << -1 << endl; return; }
            else if (str[j] == '1') b -= 2;
            else if (str[j] == '?') b -= 2, str[j] = '1';
        } else {
            if (str[j] == '0') str[i] = '0', a -= 2;
            else str[i] = '1', b -= 2;
        }
    }
    // ??
    for (int i = 0, j = n-1; i <= j; i++, j--) {
        if (str[i] != '?' || str[j] != '?') continue;
        if (i == j) {
            if (a > 0) str[i] = '0', a--;
            else if (b > 0) str[i] = '1', b--;
            else { cout << -1 << endl; return; }
        } else {
            if (a >= 2) str[i] = str[j] = '0', a -= 2;
            else if (b >= 2) str[i] = str[j] = '1', b -= 2;
            else { cout << -1 << endl; return; }
        }
    }
    if (a == 0 && b == 0) cout << str << endl;
    else cout << -1 << endl;
}
